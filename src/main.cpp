#include <windows.h>
#include <thread>

#include "memory.h"
#include "overlay.h"
#include "config.h"

int main() {
    SetConsoleTitle("Phantom Free");
    while (!Memory::Attach("FortniteClient-Win64-Shipping.exe"))
        std::this_thread::sleep_for(std::chrono::milliseconds(500));

    Config::Load("config.json");
    Overlay::Init();
    Overlay::Run();
    return 0;
}

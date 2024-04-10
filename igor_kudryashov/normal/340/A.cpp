#include <iostream>

using namespace std;

int main()
{
    int x, y, a, b;
    cin >> x >> y >> a >> b;

    __asm
    {
    mov ebx, 0
L:  inc ebx
    xor edx, edx
    mov eax, ebx
    idiv x
    cmp edx, 0
    jne L

    xor edx, edx
    mov eax, ebx
    idiv y
    cmp edx, 0
    jne L

    xor edx, edx
    mov eax, b
    idiv ebx
    mov b, eax

    xor edx, edx
    mov eax, a
    dec eax
    idiv ebx
    mov a, eax

    mov eax, b
    sub eax, a
    mov b, eax
    }

    cout << b << endl;

    return 0;
}
#include <iostream>
#include <cstdio>
using namespace std;

//   <|_|>

int ratio;

int Pgcd(int a, int b) {
    if (b == 0)
        return a;
    return Pgcd(b, a % b);
}

void Read() {
    scanf("%d", &ratio);
    int d = Pgcd(ratio, 100);
    printf("%d\n", 100 / d);
    return;
}

int main() {
    int nbTests;
    scanf("%d", &nbTests);
    for (int i = 0; i < nbTests; i ++)
    {
        Read();
    }
    return 0;
}
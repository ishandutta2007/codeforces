#include <iostream>
#include <cstdio>
using namespace std;

//    <|_|>

int nbDominos, nbUp, nbDown, nbW, nbB;

void Read() {
    scanf("%d%d%d%d%d", &nbDominos, &nbUp, &nbDown, &nbW, &nbB);
    int totW = nbUp + nbDown, totB = 2 * nbDominos - totW;
    if (totW >= 2 * nbW && totB >= 2 * nbB)
        printf("YES\n");
    else
        printf("NO\n");
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
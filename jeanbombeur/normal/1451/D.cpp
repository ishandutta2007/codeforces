#include <iostream>
#include <cstdio>
#define int long long
using namespace std;

// <|_|>

const int MAX_VALEURS = (1000 * 1000);

int nbTests;
int nbmove, distMax;

int Dicho(int d, int k) {
    int gauche = 0;
    int droite = d;
    int milieu = (gauche + droite + 1) / 2;
    while (gauche < droite)
    {
        if (2 * milieu * milieu <= (d * d) / (k * k))
        {
            gauche = milieu;
        }
        else
        {
            droite = milieu - 1;
        }
        milieu = (gauche + droite + 1) / 2;
    }
    return milieu;
}

void Read() {
    scanf("%lld%lld\n", &distMax, &nbmove);
    int a = Dicho(distMax, nbmove);
    if (2 * a * a + 2 * a + 1 <= (distMax * distMax) / (nbmove * nbmove))
    {
        printf("Ashish\n");
        return;
    }
    printf("Utkarsh\n");
    return;
}

signed main() {
    scanf("%lld", &nbTests);
    for (int i = 0; i < nbTests; i ++)
    {
        Read();
    }
    return 0;
}
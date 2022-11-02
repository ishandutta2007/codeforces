#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//  Petit coup de chance

const int MAX_VALEURS = (200 * 1000);

int Val[MAX_VALEURS];

int nbValeurs;

void Read() {
    scanf("%lld", &nbValeurs);
    
    nbValeurs ++;
    
    if (nbValeurs <= 7)
    {
        printf("15\n");
    }
    else if (nbValeurs % 6 <= 1)
    {
        printf("%lld\n", (nbValeurs / 6) * 15);
    }
    else if (nbValeurs % 6 <= 3)
    {
        printf("%lld\n", (nbValeurs - 8) / 6 * 15 + 20);
    }
    else
    {
        printf("%lld\n", (nbValeurs - 10) / 6 * 15 + 25);
    }
    return;
}

signed main() {
    int nbTests = 1;
    scanf("%lld", &nbTests);
    while (nbTests --)
    {
        Read();
    }
    return 0;
}
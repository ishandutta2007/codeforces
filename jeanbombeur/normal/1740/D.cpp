#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//  M. Broccoli

const int MAX_VALUES = (1e6);

int Occ[MAX_VALUES];

int nbRows, nbColumns, nbCards;

void Read() {
    scanf("%lld %lld %lld\n", &nbRows, &nbColumns, &nbCards);
    int maxi = 0;
    int nb = 0;
    int top = nbCards - 1;
    fill_n(Occ, nbCards, 0);
    for (int i = 0; i < nbCards; i ++)
    {
        int a;
        scanf("%lld", &a);
        Occ[-- a] ++;
        maxi = max(maxi, ++ nb);
        while (Occ[top])
            top --, nb --;
    }
    printf(maxi + 2 >= nbRows * nbColumns ? "TIDAK\n" : "YA\n");
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
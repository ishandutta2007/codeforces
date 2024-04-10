#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//   <|_|>
// Check yourself before you Shrek yourself
// The hardest choices require the strongest wills

const int MAX_VALEURS = (100 * 1000);

int Val[MAX_VALEURS];

int nbValeurs;

void Read() {
    scanf("%lld", &nbValeurs);
    for (int i = 0; i < 2 * nbValeurs; i ++)
    {
        scanf("%lld", &Val[i]);
    }
    sort(Val, Val + 2 * nbValeurs);
    for (int i = 0; i < nbValeurs; i ++)
    {
        printf("%lld %lld ", Val[i], Val[2 * nbValeurs - 1 - i]);
    }
    printf("\n");
    return;
}

signed main() {
    int nbTests;
    scanf("%lld", &nbTests);
    for (int i = 0; i < nbTests; i ++)
    {
        Read();
    }
    return 0;
}
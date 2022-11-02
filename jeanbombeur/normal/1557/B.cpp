#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;

//  <|_|>

//  What are you doing in my swamp ?

const int MAX_VALEURS = (200 * 1000);

pair <int, int> Val[MAX_VALEURS];

int nbValeurs, nbBlocs;

void Read() {
    scanf("%lld %lld", &nbValeurs, &nbBlocs);
    for (int i = 0; i < nbValeurs; i ++)
    {
        scanf("%lld", &Val[i].first);
        Val[i].second = i;
    }
    sort(Val, Val + nbValeurs);
    int nb = 1;
    for (int i = 1; i < nbValeurs; i ++)
    {
        nb += (Val[i].second - Val[i - 1].second - 1) != 0;
    }
    if (nb <= nbBlocs)
        printf("YES\n");
    else
        printf("NO\n");
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
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;

//  <|_|>

//  The hardest choices require the strongest wills
//  We must be better

const int MAX_VALEURS = (200 * 1000);

char Val[MAX_VALEURS];
char Sorted[MAX_VALEURS];

int nbValeurs;

void Read() {
    scanf("%lld%s", &nbValeurs, Val);
    int ans = 0;
    for (int i = 0; i < nbValeurs; i ++)
    {
        Sorted[i] = Val[i];
    }
    sort(Sorted, Sorted + nbValeurs);
    for (int i = 0; i < nbValeurs; i ++)
    {
        ans += Val[i] != Sorted[i];
    }
    printf("%lld\n", ans);
    return;
}

signed main() {
    int nbTests = 1;
    scanf("%lld", &nbTests);
    for (int i = 0; i < nbTests; i ++)
    {
        Read();
    }
    return 0;
}
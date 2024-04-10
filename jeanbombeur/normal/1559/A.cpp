#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//  I'm Batman

const int MAX_VALEURS = (200 * 1000);

int Val[MAX_VALEURS];

int nbValeurs;

void Solve() {
    scanf("%lld", &nbValeurs);
    
    int ans = (1LL << 30) - 1;
    
    for (int i = 0; i < nbValeurs; i ++)
    {
        scanf("%lld", &Val[i]);
        ans &= Val[i];
    }
    
    printf("%lld\n", ans);
    return;
}

signed main() {
    int nbTests = 1;
    scanf("%lld", &nbTests);
    while (nbTests --)
    {
        Solve();
    }
    return 0;
}
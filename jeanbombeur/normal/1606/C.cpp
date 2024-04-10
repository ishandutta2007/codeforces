#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//  xiao xiao

const int MAX_VALUES = (2e5);

// char String[MAX_VALUES];

int nbBanknotes, nbMin;

void Solve() {
    scanf("%lld %lld", &nbBanknotes, &nbMin);
    nbMin ++;
    int ans = 0;
    int bit = 1;
    int last = 1;
    for (int i = 0; i < nbBanknotes; i ++)
    {
        int a;
        scanf("%lld", &a);
        bit = 1;
        for (int k = 0; k < a; k ++)
            bit *= 10;
        int buff = min((bit / last) - 1, nbMin);
        ans += buff * last;
        nbMin -= buff;
        last = bit;
    }
    ans += last * nbMin;
    printf("%lld\n", ans);
    return;
}

signed main() {
    int nbTests = 1;
    scanf("%lld", &nbTests);
    while (nbTests --)
        Solve();
    return 0;
}
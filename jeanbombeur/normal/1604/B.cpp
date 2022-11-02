#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//  xiao xiao

const int MAX_VALUES = (1e5);

int Val[MAX_VALUES];

int nbValues;

void Solve() {
    scanf("%lld", &nbValues);
    int ans = 1;
    for (int i = 0; i < nbValues; i ++)
    {
        scanf("%lld", &Val[i]);
        if (i)
            ans &= Val[i - 1] < Val[i];
    }
    printf((nbValues & 1) && ans ? "NO\n" : "YES\n");
    return;
}

signed main() {
    int nbTests = 1;
    scanf("%lld", &nbTests);
    while (nbTests --)
        Solve();
    return 0;
}
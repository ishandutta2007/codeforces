#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  I've been looking forward to this

//  <|_|>

const int MAX_VALUES = (2e5);

int Val[MAX_VALUES];

int nbValues, start;

void Solve() {
    scanf("%lld %lld", &nbValues, &start);
    int ans = 0;
    for (int i = 0; i < nbValues; i ++)
    {
        scanf("%lld", &Val[i]);
        ans = max(ans, Val[i] | start);
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
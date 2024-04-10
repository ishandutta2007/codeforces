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

void Solve() {
    int n, k;
    scanf("%lld %lld\n", &n, &k);
    int tot = 1, cnt = 0;
    while (tot < k)
        tot <<= 1, cnt ++;
    cnt += (n - tot + k - 1) / k;
    printf("%lld\n", cnt);
    return;
}

signed main() {
    int nbTests = 1;
    scanf("%lld", &nbTests);
    while (nbTests --)
        Solve();
    return 0;
}
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//  Spared no expense

void Solve() {
    int left, right;
    scanf("%lld %lld", &left, &right);
    int opt = max(left, (right + 1) / 2);
    printf("%lld\n", min(right, 2 * opt - 1) % opt);
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
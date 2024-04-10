#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//  A wizard is never late nor early. He arrives precisely when he means to

void Solve() {
    int a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);
    int n = abs(a - b);
    if (max(a, max(b, c)) > 2 * n)
        printf("-1\n");
    else
        printf("%lld\n", c <= n ? c + n : c - n);
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
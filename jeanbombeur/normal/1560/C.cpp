#include <iostream>
#include <cstdio>
#include <cmath>
#define int long long
using namespace std;

//  <|_|>

//  A wizard is never late nor early. He arrives precisely when he means to

void Solve() {
    int n;
    scanf("%lld", &n);
    int k = sqrt(n - 1);
    n -= k * k;
    if (n <= k)
        printf("%lld %lld\n", n, k + 1);
    else
        printf("%lld %lld\n", k + 1, 2 * k + 2 - n);
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
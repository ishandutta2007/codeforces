#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//  xiao xiao

void Solve() {
    int n;
    scanf("%lld", &n);
    while (n > 9)
    {
        int m = 0;
        while (n > 0)
            m += n % 10, n /= 10;
        n = m;
    }
    printf("%lld\n", n);
    return;
}

signed main() {
    int nbTests = 1;
    // scanf("%lld", &nbTests);
    while (nbTests --)
        Solve();
    return 0;
}
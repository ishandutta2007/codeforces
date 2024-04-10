#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//  A wizard is never late nor early. He arrives precisely when he means to

void Solve() {
    int n;
    scanf("%lld", &n);
    int cur = 0;
    for (int i = 0; i < n; i ++)
    {
        cur ++;
        while (cur % 10 == 3 || cur % 3 == 0)
            cur ++;
    }
    printf("%lld\n", cur);
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
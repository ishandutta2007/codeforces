#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

const int MAX_VALUES = (2e5);

int Val[MAX_VALUES];

int nbValues;

void Solve() {
    int x, y;
    scanf("%lld %lld", &x, &y);
    if (x == y)
        printf("%lld\n", x);
    else if (x > y)
        printf("%lld\n", x + y);
    else
    {
        int k = (x + y - 1) / x;
        printf("%lld\n", (y + (k - 1) * x) / 2);
    }
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
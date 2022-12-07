#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

ll n, pow4[105];

int main() {
    scanf("%lld", &n);
    ll m = 2 * n - 2;
    ll ans = 0;
    pow4[0] = 1;
    for (int i = 1; i < m; i++) pow4[i] = pow4[i - 1] * 4;
    if (m - n - 1 >= 0) ans += 4 * 3 * pow4[m - n - 1] * 2;
    if (m - n - 2 >= 0) ans += 4 * 3 * 3 * pow4[m - n - 2] * (m - n - 1);
    printf("%lld\n", ans);
    return 0;
}
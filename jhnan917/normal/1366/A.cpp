#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        ll a, b;
        scanf("%lld %lld", &a, &b);
        ll s = 0, e = 1e9;
        while (s < e) {
            ll m = (s + e + 1) / 2;
            if (a >= m && b >= m && a + b >= 3 * m) s = m;
            else e = m - 1;
        }
        printf("%lld\n", s);
    }
}
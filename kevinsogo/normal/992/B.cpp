#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll l, r, x, y;
    scanf("%lld%lld%lld%lld", &l, &r, &x, &y);
    l--;
    ll ans = 0;
    if (y % x == 0) {
        l /= x;
        r /= x;
        y /= x;
        for (ll a = 1; a * a <= y; a++) {
            if (y % a == 0 && l < a && a <= r) {
                ll b = y / a;
                if (l < b && b <= r && __gcd(a, b) == 1) ans += 1 + (a != b);
            }
        }

    }
    printf("%lld\n", ans);
}
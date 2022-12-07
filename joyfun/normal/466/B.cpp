#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;

ll n, a, b;

int main() {
    scanf("%lld%lld%lld", &n, &a, &b);
    n = n * 6;
    ll ans = 1e18, x, y;
    if (a * b >= n) {
        x = a;
        y = b;
        ans = a * b;
    }
    else {
        int flag = 0;
        if (a > b) {
            flag = 1;
            swap(a, b);
        }
        for (int i = 1; i < 1000000 && i < n; i++) {
            ll r = n / i + (n % i != 0);
            ll l = i;
            if (l > r) swap(l, r);
            if (l < a || r < b) continue;
            if (i * r < ans) {
                ans = i * r;
                x = i;
                y = r;
            }
        }
        if (flag) swap(x, y);
    }
    printf("%lld\n%lld %lld\n", ans, x, y);
    return 0;
}
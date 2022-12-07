#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
typedef long long ll;

int n, k, a[N];
map<ll, int> H;

ll gao(ll x) {
    H.clear(); H[0] = 1;
    ll s = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        s += a[i];
        if (H.count(s - x)) ans += H[s - x];
        H[s]++;
    }
    return ans;
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    if (k == 1) {
        printf("%lld\n", gao(1));
    } else if (k == -1) {
        printf("%lld\n", gao(1) + gao(-1));
    } else {
        ll x = 1, ans = 0;
        for (int i = 0; ; i++) {
            if (max(x, -x) > (ll)(1e14)) break;
            ans += gao(x);
            x *= k;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
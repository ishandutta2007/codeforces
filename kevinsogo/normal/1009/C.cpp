#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline ll c2(ll n) {
    return n * (n - 1) / 2;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    ll ans = 0;
    while (m--) {
        ll x, d;
        scanf("%lld%lld", &x, &d);
        ans += x * n + max(d * c2(n), d * (c2((n + 1) / 2) + c2(n / 2 + 1)));
    }
    printf("%.11lf\n", (double)ans / n);
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll f(ll x, ll y) {
    return (y+1)*x*(x+1)/2 + (x+1)*y*(y+1)/2;
}

int main() {
    ll m, b;
    scanf("%lld%lld", &m, &b);
    ll ans = 0;
    for (ll x = 0; x <= m*b; x++) {
        ll y = -((x+m-1)/m) + b;
        assert(y >= 0);
        ans = max(ans, f(x, y));
    }
    printf("%lld\n", ans);
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n;
    ll a;
    scanf("%d%lld%*s", &n, &a);
    map<ll,ll> inters;
    map<pair<ll,ll>,ll> sames;
    ll ans = 0;
    while (n--) {
        ll x, y;
        scanf("%*s%lld%lld", &x, &y);
        ll v = a*x - y;
        pair<ll,ll> p = {x, y};
        ans += inters[v] - sames[p];
        inters[v]++;
        sames[p]++;
    }
    printf("%lld\n", ans << 1);
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 211111;
#define hp first
#define dmg second

typedef pair<ll,ll> guy;

ll gain(guy& g) {
    return max(0LL, g.hp - g.dmg);
}
guy gs[N];
int main() {
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &gs[i].hp, &gs[i].dmg);
    }
    sort(gs, gs + n, [](guy x, guy y) {
        return gain(x) > gain(y);
    });
    ll plain = 0;
    for (int i = 0; i < n; i++) {
        plain += gs[i].dmg + (i < b ? gain(gs[i]) : 0);
    }
    ll ans = plain;
    if (b > 0) {
        for (int i = 0; i < n; i++) {
            ans = max(ans, plain - gs[i].dmg - gain(gs[min(i, b - 1)]) + (gs[i].hp << a));
        }
    }
    printf("%lld\n", ans);
}
#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;

int n, k, s, t;
ll c[200005], v[200005];
ll g[200005];

int main() {
    scanf("%d %d %d %d", &n, &k, &s, &t);
    FO(i,0,n) scanf("%lld %lld", c+i, v+i);
    FO(i,0,k) scanf("%lld", g+i);
    g[k++] = 0;
    g[k++] = s;
    sort(g,g+k);

    ll st = 0, en = 1e10, bst = -1;
    while (st <= en) {
        ll md = (st+en)/2;

        ll f = 0;
        FO(i,0,n) if (c[i] <= md) f = max(f,v[i]);

        ll tt = 0;
        FO(i,0,k-1) {
            ll d = g[i+1]-g[i];
            if (d > f) {
                tt += t+1;
            } else {
                ll o = min(f-d, d);
                tt += 2*d-o;
            }
        }
        if (tt > t) st = md+1;
        else {
            en = md-1;
            bst = md;
        }
    }
    printf("%lld\n", bst);
}
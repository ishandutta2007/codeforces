#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;

int n;

pair<ll,int> v[400010];
struct RT {

    void st(int i, ll c) {
        i += n;
        v[i] = {c,i-n};
        for (; i>1; i/=2) v[i/2] = min(v[i],v[i^1]);
    }

    pair<ll,int> qu(int l, int r) {
        pair<ll,int> a(1e12,-1);
        for (l+=n,r+=n; l < r;l /= 2, r/=2) {
            if (l&1) a = min(a,v[l++]);
            if (r&1) a = min(a,v[--r]);
        }
        return a;
    }
} rt;

pair<ll,ll> gs[200005];
ll d;
ll f;

int main() {
    scanf("%lld %lld %d", &d, &f, &n);
    FO(i,0,n) {
        scanf("%lld %lld", &gs[i].first, &gs[i].second);
    }
    gs[n++] = make_pair(0,0);
    gs[n++] = make_pair(d,0);
    sort(gs,gs+n);
    FO(i,0,n) rt.st(i, gs[i].second);

    ll ans = 0;
    int lrf = 0; ll lrfa = f; // last refueled at lrf to an amount of lrfa
    for (int i = 0; i < n-1; i++) {
start:;
        // currently at i
        ll nx = gs[i+1].first;
        if (nx - gs[lrf].first > lrfa) {
            // need more fuel
            ll need = (nx-gs[lrf].first) - lrfa;
            int lp = lrfa == f ? lrf+1 : lrf;
            if (lp > i) {
                printf("-1\n");
                return 0;
            }
            pair<ll,int> bst = rt.qu(lp,i+1);
            ll att = lrfa - (gs[bst.second].first - gs[lrf].first);
            lrf = bst.second; lrfa = att;
            ll gt = min(need, f-att);
            lrfa += gt;
            ans += gt * gs[bst.second].second;
            goto start;
        }
    }
    printf("%lld\n", ans);
}
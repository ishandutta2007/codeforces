#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll Q = 1e7+19, M = 1e9+7;

ll n, k, m, curq;

struct thing {
    ll w, v, s, e;
}a[35005];

struct segtree {
    vector<pair<ll,ll> > qry[120005];
    ll val[25][1005];
    void update (ll S, ll E, ll SS, ll SE, ll P, ll W, ll V) {
        if(S<=SS && SE<=E) {qry[P].push_back({W, V}); return;}
        if(E<SS || SE<S) return;
        ll mid = (SS+SE)/2;
        update(S, E, SS, mid, 2*P, W, V);
        update(S, E, mid+1, SE, 2*P+1, W, V);
    }
    void traverse (ll SS, ll SE, ll P, ll D) {
        for(int i=0;i<=k;i++) val[D][i] = val[D-1][i];
        for(int i=0;i<qry[P].size();i++) {
            ll W = qry[P][i].first, V = qry[P][i].second;
            for(int j=k;j>=W;j--) {
                val[D][j] = max(val[D][j], val[D][j-W]+V);
            }
        }
        if(SS == SE) {
            ll ret = 0, bas = 1;
            for(ll i=1;i<=k;i++) {
                ret = (ret+bas*val[D][i])%M;
                bas = bas*Q%M;
            }
            printf("%lld\n",ret);
        }
        else {
            ll mid = (SS+SE)/2;
            traverse(SS, mid, 2*P, D+1);
            traverse(mid+1, SE, 2*P+1, D+1);
        }
    }
}seg;

int main()
{
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i++) {
        scanf("%lld%lld",&a[i].v,&a[i].w);
        a[i].s = curq; a[i].e = -2;
    }
    scanf("%lld",&m);
    for(int i=1;i<=m;i++) {
        ll typ;
        scanf("%lld",&typ);
        if(typ == 1) {
            n++;
            scanf("%lld%lld",&a[n].v,&a[n].w);
            a[n].s = curq; a[n].e = -2;
        }
        if(typ == 2) {
            ll X;
            scanf("%lld",&X);
            a[X].e = curq-1;
        }
        if(typ == 3) curq++;
    }
    for(int i=1;i<=n;i++) {
        if(a[i].e == -2) a[i].e = curq-1;
        if(a[i].s > a[i].e) continue;
        seg.update(a[i].s, a[i].e, 0, curq-1, 1, a[i].w, a[i].v);
    }
    seg.traverse(0, curq-1, 1, 1);
}
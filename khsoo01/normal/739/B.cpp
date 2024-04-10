#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, a[200005], p[20][200005], v[20][200005];
ll s[200005], e[200005], ccnt;
vector<ll> cg[200005], cv[200005];

struct segtree {
    ll val[888888], lim;
    void init () {
        for(lim=1;lim<=n;lim<<=1);
    }
    void update (ll P, ll X) {
        P += lim;
        while(P) {
            val[P] += X;
            P>>=1;
        }
    }
    ll query (ll S, ll E) {
        S += lim; E += lim;
        ll ret = 0;
        while(S <= E) {
            if(S % 2 == 1) {ret += val[S]; S++;}
            if(E % 2 == 0) {ret += val[E]; E--;}
            S>>=1; E>>=1;
        }
        return ret;
    }
}seg;

void calc (ll cur) {
    s[cur] = ++ccnt;
    for(int i=0;i<cg[cur].size();i++) {
        calc(cg[cur][i]);
    }
    e[cur] = ccnt;
}

ll firstover (ll idx, ll V) {
    ll tmp = 0;
    for(int i=20;i--;) {
        if(tmp + v[i][idx] <= V) {
            tmp += v[i][idx];
            idx = p[i][idx];
        }
    }
    return p[0][idx];
}

int main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    v[0][1] = 1e18;
    for(int i=2;i<=n;i++) {
        scanf("%lld%lld",&p[0][i],&v[0][i]);
        cg[p[0][i]].push_back(i);
        cv[p[0][i]].push_back(v[0][i]);
    }
    calc(1);
    for(int k=1;k<20;k++) {
        for(int i=1;i<=n;i++) {
            v[k][i] = v[k-1][i] + v[k-1][p[k-1][i]];
            p[k][i] = p[k-1][p[k-1][i]];
        }
    }
    seg.init();
    for(int i=1;i<=n;i++) {
        seg.update(s[i], 1);
        seg.update(s[firstover(i, a[i])], -1);
    }
    for(int i=1;i<=n;i++) {
        printf("%lld ",seg.query(s[i], e[i])-1);
    }
}
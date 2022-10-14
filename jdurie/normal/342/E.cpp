//Centroid Decomposition
#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pl;

#define G(x) ll x; cin >> x;
#define F(i, l, r) for(ll i = l; i < (r); i++)
#define N 100010

vector<ll> tree[N];
ll sz[N], cPar[N], lvl[N]; //lvl is 1-indexed

ll getSize(ll i, ll p) {
    sz[i] = 1;
    for(ll j : tree[i])
        if(j - p && !lvl[j])
            sz[i] += getSize(j, i);
    return sz[i];
}

ll centroid(ll i, ll p, ll n) {
    for(ll j : tree[i])
        if(j - p && !lvl[j] && sz[j] > n / 2)
            return centroid(j, i, n);
    return i;
}

ll decomp(ll i, ll l) {
    ll cent = centroid(i, -1, getSize(i, -1));
    lvl[cent] = l;
    for(ll j : tree[cent]) if(!lvl[j])
        cPar[decomp(j, l + 1)] = cent;
    return cent;
}

#define FD(i, r, l) for(ll i = r; i > l; i--)
#define L 20
ll dst[N], dep[N], par[N][L];

void dfs(ll i, ll p, ll d) {
    dep[i] = d;
    par[i][0] = p;
    F(l, 1, L) par[i][l] = par[par[i][l - 1]][l - 1];
    for(ll j : tree[i]) if(j - p) dfs(j, i, d + 1);
}

ll lca(ll a, ll b) {
    if(dep[a] < dep[b]) swap(a, b);
    FD(l, L - 1, -1) if((dep[a] - dep[b]) >> l) a = par[a][l];
    if(a == b) return a;
    FD(l, L - 1, -1) if(par[a][l] - par[b][l]) a = par[a][l], b = par[b][l];
    return par[a][0];
}

#define DIST(a, b) (dep[a] + dep[b] - 2 * dep[lca(a, b)])

void paintRed(ll u) {
    ll v = u;
    while(v) {
        dst[v] = min(dst[v], DIST(u, v));
        v = cPar[v];
    }
}

ll distRed(ll u) {
    ll ans = N, v = u;
    while(v) {
        ans = min(ans, dst[v] + DIST(u, v));
        v = cPar[v];
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) G(m)
    fill_n(dst, n + 1, n);
    F(i, 0, n - 1) {
        G(u) G(v)
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    decomp(1, 1);
    dfs(1, 1, 1);
    paintRed(1);
    while(m--) {
        G(t) G(v)
        if(t == 1) paintRed(v);
        else cout << distRed(v) << '\n';
    }
}
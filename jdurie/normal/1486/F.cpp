#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
template<class T, class S>
ostream& operator << (ostream &o, const pair<T, S> &p) {
    return o << '(' << p.first << ", " << p.second << ')';
}
template<template<class, class...> class T, class... A>
typename enable_if<!is_same<T<A...>, string>(), ostream&>::type
operator << (ostream &o, T<A...> V) {
	o << '[';
	for(auto a : V) o << a << ", ";
	return o << ']';
}

typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pl;

#define G(x) ll x; cin >> x;
#define GD(x) ld x; cin >> x;
#define GS(s) string s; cin >> s;
#define F(i, l, r) for(ll i = l; i < (r); ++i)
#define FD(i, r, l) for(ll i = r; i > (l); --i)
#define P(a, n) { cout << "{ "; F(_, 0, n) cout << a[_] << " "; cout << "}\n"; }
#define EX(x) { cout << x << '\n'; exit(0); }
#define A(a) (a).begin(), (a).end()
#define K first
#define V second
#define M 1000000007 //998244353
#define N 300010
#define L 20

ll n, m, dep[N], par[N][L];
vector<ll> tree[N];
ll x[N], y[N], sx[N], sy[N], lc[N], lcp[N], pp[N], ct[N];
map<pl, ll> reee2;

#define C(x, y) make_pair(min(x, y), max(x, y))

void dfs(ll i, ll p) {
    dep[i] = dep[p] + 1;
    par[i][0] = p;
    F(l, 1, L) par[i][l] = par[par[i][l - 1]][l - 1];
    for(ll j : tree[i]) if(j - p) dfs(j, i);
}

ll lca(ll a, ll b) {
    if(dep[a] < dep[b]) swap(a, b);
    FD(l, L - 1, -1) if((dep[a] - dep[b]) >> l) a = par[a][l];
    if(a == b) return a;
    FD(l, L - 1, -1) if(par[a][l] - par[b][l]) a = par[a][l], b = par[b][l];
    return par[a][0];
}

ll spar(ll i, ll a) {
    if(i == a) return -1;
    ll k = dep[i] - dep[a] - 1;
    FD(l, L - 1, -1) if((k >> l) & 1) i = par[i][l];
    return i;
}

ll dfs2(ll i) {
    for(ll j : tree[i]) if(j - par[i][0]) pp[i] += dfs2(j);
    return pp[i];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    F(i, 0, n - 1) {
        G(u) G(v)
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(1, 1);
    cin >> m;
    F(i, 0, m) {
        cin >> x[i] >> y[i];
        lc[i] = lca(x[i], y[i]);
        sx[i] = spar(x[i], lc[i]);
        sy[i] = spar(y[i], lc[i]);
        ct[lc[i]]++;
        lcp[sx[i]]++;
        lcp[sy[i]]++;
        reee2[C(sx[i], sy[i])]++;
        pp[x[i]]++;
        pp[y[i]]++;
        pp[lc[i]] -= 2;
    }
    dfs2(1);
    F(i, 1, n + 1) pp[i] -= lcp[i];
    ll ans = 0, ans2 = 0;
    /*P(pp, n + 1) P(lcp, n + 1)
    P(ct, n + 1)
    cout << reee2 << '\n';*/
    F(i, 1, n + 1) for(ll j : tree[i]) if(j - par[i][0]) ans += pp[j] * (ct[i] - lcp[j]);
    F(i, 0, m) {
        ans2 += ct[lc[i]] - 1;
        if(~sx[i]) ans2 -= (lcp[sx[i]] - 1);
        if(~sy[i]) ans2 -= (lcp[sy[i]] - 1);
        if(~sx[i] && ~sy[i]) ans2 += (reee2[C(sx[i], sy[i])] - 1);
        if(x[i] - lc[i]) ans += ct[x[i]];
        if(y[i] - lc[i]) ans += ct[y[i]];
    }
    cout << ans + ans2 / 2 << '\n';
}
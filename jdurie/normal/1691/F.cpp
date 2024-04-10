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
#define E 600010
#define N 200010
#define NCR(n, r) (f[n] * fi[r] % M * fi[(n) - (r)] % M)

ll n, k, sz[E], nck[N], dpv[N], sts[N], par[N];
pl e[E];
vector<pl> tree[N];

ll inv(ll a, ll b = M) { return 1 < a ? b - inv(b % a, a) * b / a : 1; }

ll dfs(ll i, ll p) {
    par[i] = p;
    sts[i] = 1;
    for(pl q : tree[i]) if(q.K - p) sts[i] += dfs(q.K, i);
    return sts[i];
}

int main() {
    memset(sz, -1, sizeof sz);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    nck[k] = 1;
    F(i, k + 1, N) nck[i] = nck[i - 1] * i % M * inv(i - k) % M;
    F(i, 0, n - 1) {
        G(u) G(v)
        tree[u].emplace_back(v, 2 * i + 1);
        tree[v].emplace_back(u, 2 * i);
        e[2 * i] = {u, v};
        e[2 * i + 1] = {v, u};
    }
    F(i, 0, n) e[2 * (n - 1) + i] = {i + 1, i + 1};
    ll ans = 0;
    dfs(1, 1);
    F(i, 0, 2 * (n - 1)) sz[i] = par[e[i].K] == e[i].V ? sts[e[i].K] : n - sts[e[i].V];
    F(i, 2 * (n - 1), 2 * (n - 1) + n) sz[i] = n;
    F(u, 1, n + 1) for(pl q : tree[u]) dpv[u] = (dpv[u] + M - nck[sz[q.V]]);
    F(i, 0, 2 * (n - 1) + n) {
        ll u = e[i].K, dpi = nck[sz[i]] + dpv[u] + (i >= 2 * (n - 1) ? 0 : nck[sz[i ^ 1]]);
        ans = (ans + dpi % M * max(1ll, n - sz[i]) % M * sz[i]) % M;
    }
    cout << ans << '\n';
}
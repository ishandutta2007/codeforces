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
#define N 210
#define L 8

ll dep[N], par[N][L];
ll f[N], fi[N], p2[N], ip2[N], prob[N][N];
vector<ll> tree[N];

ll inv(ll a, ll b = M) { return 1 < a ? b - inv(b % a, a) * b / a : 1; }
#define NCR(n, r) (f[n] * fi[r] % M * fi[(n) - (r)] % M)

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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    f[0] = fi[0] = p2[0] = 1;
    F(i, 1, N) f[i] = i * f[i - 1] % M, fi[i] = inv(f[i]), p2[i] = 2 * p2[i - 1] % M, ip2[i] = inv(p2[i]);
    G(n) ll in = inv(n);
    F(i, 0, n - 1) {
        G(u) G(v)
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    F(c, 0, N) F(d, 0, N)
        if(c == 0) prob[c][d] = 1;
        else if(d == 0) prob[c][d] = 0;
        else F(i, 0, d) prob[c][d] = (prob[c][d] + NCR(c - 1 + i, i) * ip2[c + i]) % M;
    ll invs = 0;
    F(k, 1, n + 1) {
        dfs(k, k);
        F(i, 1, n + 1) F(j, 1, i) {
            ll l = lca(i, j);
            ll di = dep[i] - dep[l], dj = dep[j] - dep[l];
            invs = (invs + prob[di][dj] * in) % M;
        }
    }
    cout << invs << '\n';
}
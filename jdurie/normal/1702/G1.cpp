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
#define N 200010
#define L 20

ll dep[N], par[N][L];
vector<ll> tree[N];

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
    G(n)
    F(i, 0, n - 1) {
        G(u) G(v)
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(1, 1);
    G(q) while(q--) {
        G(k) vector<ll> v;
        F(i, 0, k) { G(x) v.push_back(x); }
        ll l = v[0];
        F(i, 1, k) l = lca(l, v[i]);
        sort(A(v), [](ll a, ll b) { return dep[a] > dep[b]; });
        ll j = 1;
        while(j < k && lca(v[j], v[0]) == v[j]) j++;
        string ans = (j == k || lca(v[j], v[0]) == l) ? "YES\n" : "NO\n";
        F(i, 0, k) if(!(lca(v[i], v[0]) == v[i] || lca(v[i], v[j]) == v[i])) ans = "NO\n";
        cout << ans;
    }
}
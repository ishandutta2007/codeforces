#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
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
#define F(i, l, r) for(ll i = l; i < r; i++)
#define FD(i, r, l) for(ll i = r; i > l; i--)
#define P(a, n) { cout << "{ "; F(_, 0, n) cout << a[_] << " "; cout << "}\n"; }
#define EX(x) { cout << x << '\n'; exit(0); }
#define A(x) (x).begin(), (x).end()
#define K first
#define V second
#define M 1000000007 //998244353
#define N 200010
#define L 20

ll dep[N], par[N][L];
vector<ll> tree[N];

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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) G(m)
    F(i, 0, n - 1) {
        G(u) G(v)
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(1, 1, 0);
    while(m--) {
        vector<pl> v;
        G(x) while(x--) { G(k) v.emplace_back(dep[par[k][0]], par[k][0]); }
        sort(A(v));
        string ans = "YES\n";
        for(int i = 0; i + 1 < (ll)v.size(); i++) 
            if(lca(v[i].V, v[i + 1].V) != v[i].V) ans = "NO\n";
        cout << ans;
    }
}
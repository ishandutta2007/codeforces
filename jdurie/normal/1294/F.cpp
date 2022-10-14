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

vector<ll> tree[N];
vector<pl> bfs;
bool used[N];
ll par[N];

pl dfs(ll i, ll p) {
    par[i] = p;
    pl ans = {0, i};
    for(ll j : tree[i]) if(j - p) {
        pl x = dfs(j, i); x.K++;
        ans = max(ans, x);
    }
    return ans;
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
    ll u = dfs(1, 1).V, v = dfs(u, u).V;
    ll ans = 0, t = v;
    while(1) {
        bfs.emplace_back(0, t), used[t] = true;
        if(t == u) break; else ans++, t = par[t];
    }
    ll idx = -1;
    pl mx; F(i, 1, n + 1) if(i - u && i - v) mx = {0, i};
    while(++idx < bfs.size()) {
        if(bfs[idx].K) mx = max(mx, bfs[idx]);
        for(ll j : tree[bfs[idx].V]) if(!used[j]) bfs.emplace_back(bfs[idx].K + 1, j), used[j] = true;
    }
    cout << ans + mx.K << '\n';
    cout << u << ' ' << v << ' ' << mx.V << '\n';
}
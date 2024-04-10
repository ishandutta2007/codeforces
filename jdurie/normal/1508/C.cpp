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

set<ll> graph[N];
map<pl, ll> wt;
ll par[N], par2[N];

ll dsu(ll i) { return par[i] == i ? i : par[i] = dsu(par[i]); }
ll dsu2(ll i) { return par2[i] == i ? i : par2[i] = dsu2(par2[i]); }

#define CAN(u, v) pl{min(u, v), max(u, v)}
void add_edge(ll u, ll v, ll w) {
    graph[u].insert(v);
    graph[v].insert(u);
    wt[CAN(u, v)] = w;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    iota(par, par + N, 0);
    iota(par2, par2 + N, 0);
    G(n) G(m) ll xr = 0;
    F(i, 0, m) { G(u) G(v) G(w) add_edge(u, v, w); xr ^= w; }
    if(n * (n - 1) / 2 - m >= n) {
        ll u = 1;
        F(v, 2, n + 1) if(graph[v].size() < graph[u].size()) u = v;
        for(ll v1 : graph[u]) {
            for(ll v2 : graph[u]) if(v1 - v2 && !graph[v1].count(v2)) add_edge(v1, v2, 0);
            if(graph[v1].size() != n - 1) add_edge(u, v1, 0);
        }
        F(v, 1, n + 1) if(v - u && !graph[u].count(v)) add_edge(u, v, 0);
        vector<pair<ll, pl>> vec;
        F(v1, 1, n + 1) for(ll v2 : graph[v1]) if(v2 > v1) vec.push_back({wt[CAN(v1, v2)], {v1, v2}});
        sort(A(vec));
        ll ans = 0;
        for(auto a : vec) {
            ll v1 = a.V.K, v2 = a.V.V;
            if(dsu(v1) - dsu(v2)) par[dsu(v1)] = dsu(v2), ans += a.K;
        }
        cout << ans << '\n';
    } else {
        bool spare = false;
        F(u, 1, n + 1) F(v, u + 1, n + 1) if(!graph[u].count(v)) {
            if(dsu(u) - dsu(v)) par[dsu(u)] = dsu(v);
            else spare = true;
        }
        ll temp = spare ? 0 : xr, ans = 0;
        vector<pair<ll, pl>> vec;
        F(u, 1, n + 1) for(ll v : graph[u]) if(v > u) vec.push_back({wt[CAN(u, v)], {u, v}});
        sort(A(vec));
        for(auto a : vec) {
            ll v1 = a.V.K, v2 = a.V.V;
            if(dsu(v1) - dsu(v2)) par[dsu(v1)] = dsu(v2), par2[dsu2(v1)] = dsu2(v2), ans += a.K;
            else if(dsu2(v1) - dsu2(v2)) temp = min(temp, a.K);
        }
        cout << ans + temp << '\n';
    }
}
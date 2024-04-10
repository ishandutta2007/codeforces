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

vector<pl> graph[N];
ll col[N], indeg[N], pos[N];

void dfs(ll i, ll c) {
    col[i] = c;
    for(pl p : graph[i]) {
        if(col[i] == p.V) indeg[i]++;
        if(col[p.K] == c) EX("NO")
        else if(!col[p.K]) dfs(p.K, 3 - c);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) G(m)
    while(m--) {
        G(t) G(u) G(v)
        graph[u].emplace_back(v, t);
        graph[v].emplace_back(u, t);
    }
    F(i, 1, n + 1) if(!col[i]) dfs(i, 1);
    vector<ll> src;
    F(i, 1, n + 1) if(!indeg[i]) src.push_back(i);
    F(i, 0, src.size()) for(pl p : graph[src[i]]) if(!--indeg[p.K]) src.push_back(p.K);
    if(src.size() < n) cout << "NO\n";
    else {
        cout << "YES\n";
        F(i, 0, n) pos[src[i]] = i;
        F(i, 1, n + 1) cout << " RL"[col[i]] << ' ' << pos[i] << '\n';
    }
}
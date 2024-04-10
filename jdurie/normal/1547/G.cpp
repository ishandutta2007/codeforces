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
#define N 400010

vector<ll> graph[N], rGraph[N], sccList[N], ord;
set<ll> sccGraph[N];
ll scc[N], dp[N]; //sccs are 1-indexed
bool used[N], loop[N];

void dfs1(ll i) {
    used[i] = true;
    for(ll j : graph[i]) if(!used[j]) dfs1(j);
    ord.push_back(i);
}

void dfs2(ll i, ll c) {
    scc[i] = c;
    sccList[c].push_back(i);
    for(ll j : rGraph[i]) if(!scc[j]) dfs2(j, c);
}

ll r(ll i) {
    if(dp[i] != -2) return dp[i];
    dp[i] = 0;
    for(ll j : sccGraph[i]) {
        ll v = r(j);
        if(v == -1) return dp[i] = -1;
        dp[i] += v;
    }
    if(i == scc[1]) dp[i] = 1;
    if(dp[i]) {
        if(sccList[i].size() > 1) return dp[i] = -1;
        if(loop[sccList[i][0]]) return dp[i] = -1;
    }
    return dp[i] = min(2ll, dp[i]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n) G(m)
        F(i, 1, n + 1) dp[i] = -2;
        while(m--) {
            G(u) G(v)
            if(u == v) loop[u] = true;
            else {
                graph[u].push_back(v);
                rGraph[v].push_back(u);   
            }
        }
        F(i, 1, n + 1) if(!used[i]) dfs1(i);
        ll c = 1;
        reverse(ord.begin(), ord.end());
        for(ll i : ord) if(!scc[i]) dfs2(i, c++);
        F(i, 1, n + 1) for(ll j : graph[i]) if(scc[j] - scc[i]) sccGraph[scc[j]].insert(scc[i]);
        F(i, 1, n + 1) cout << r(scc[i]) << ' ';
        cout << '\n';
        F(i, 1, n + 1) graph[i].clear(), rGraph[i].clear(), sccList[i].clear(), sccGraph[i].clear(), used[i] = false, scc[i] = 0, loop[i] = false;
        ord.clear();
    }
}
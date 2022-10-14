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

vector<pl> graph[N], rGraph[N];
vector<ll> sccList[N], ord;
set<ll> sccGraph[N];
ll scc[N], ggg[N]; //sccs are 1-indexed
bool used[N], used2[N];
ll val[N];

void dfs1(ll i) {
    used[i] = true;
    for(pl j : graph[i]) if(!used[j.K]) dfs1(j.K);
    ord.push_back(i);
}

void dfs2(ll i, ll c) {
    scc[i] = c;
    sccList[c].push_back(i);
    for(pl j : rGraph[i]) if(!scc[j.K]) dfs2(j.K, c);
}

ll dogcd(ll i, ll k) {
    return ~i ? __gcd(i, k) : k;
}

ll dfss(ll i, ll cur) {
    used2[i] = true;
    ll ans = -1;
    val[i] = cur;
    for(pl j : graph[i]) if(scc[j.K] == scc[i]) {
        if(used2[j.K]) ans = dogcd(ans, abs(val[j.K] - cur - j.V));
        else ans = dogcd(ans, dfss(j.K, cur + j.V));
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(ggg, -1, sizeof ggg);
    G(n) G(m)
    while(m--) {
        G(u) G(v) G(l)
        graph[u].emplace_back(v, l);
        rGraph[v].emplace_back(u, l);
    }
    F(i, 1, n + 1) if(!used[i]) dfs1(i);
    ll c = 1;
    reverse(ord.begin(), ord.end());
    for(ll i : ord) if(!scc[i]) dfs2(i, c++);
    F(i, 1, n + 1) for(pl j : graph[i]) if(scc[j.K] - scc[i]) sccGraph[scc[i]].insert(scc[j.K]);
    F(i, 1, c) ggg[i] = dfss(sccList[i][0], 0);
    G(q) while(q--) {
        G(v) G(s) G(t)
        cout << (s && (ggg[scc[v]] == -1 || __gcd(s, t) % __gcd(ggg[scc[v]], t)) ? "NO\n" : "YES\n");
    }
}
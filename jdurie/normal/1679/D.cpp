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

vector<ll> graph[N], topo;
ll n, k, indeg[N], idx[N], dst[N], a[N];

bool cantopo(ll m) {
    fill_n(indeg, n + 1, 0);
    F(i, 1, n + 1) for(ll j : graph[i]) if(max(a[i], a[j]) <= m) indeg[j]++;
    topo.clear();
    F(i, 1, n + 1) if(!indeg[i]) topo.push_back(i);
    F(i, 0, topo.size()) for(ll j : graph[topo[i]]) if(max(a[topo[i]], a[j]) <= m && !--indeg[j]) topo.push_back(j);
    return topo.size() == n;
}

ll bsch(ll l, ll r) {
    if(l == r) return l;
    ll m = (l + r) / 2;
    return cantopo(m) ? bsch(m + 1, r) : bsch(l, m);
}

bool canpath(ll m) {
    FD(i, n - 1, -1) if(a[topo[i]] <= m) {
        dst[topo[i]] = 1;
        for(ll j : graph[topo[i]]) if(idx[j] > i) dst[topo[i]] = max(dst[topo[i]], dst[j] + 1);
    } else dst[topo[i]] = 0;
    return *max_element(dst + 1, dst + n + 1) >= k;
}

ll bsch2(ll l, ll r) {
    if(l == r) return l;
    ll m = (l + r) / 2;
    return canpath(m) ? bsch2(l, m) : bsch2(m + 1, r);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n; G(m) cin >> k;
    F(i, 1, n + 1) cin >> a[i];
    while(m--) { G(u) G(v) graph[u].push_back(v); }
    ll mincyc = bsch(1, M);
    fill_n(indeg, n + 1, 0);
    F(i, 1, n + 1) for(ll j : graph[i]) indeg[j]++;
    topo.clear(); set<ll> unused;
    F(i, 1, n + 1) if(!indeg[i]) topo.push_back(i); else unused.insert(i);
    F(i, 0, n) {
        if(i == topo.size()) { topo.push_back(*unused.begin()); unused.erase(unused.begin()); }
        for(ll j : graph[topo[i]]) if(!--indeg[j]) topo.push_back(j), unused.erase(j);
    }
    F(i, 0, n) idx[topo[i]] = i;
    ll minpath = bsch2(1, M);
    ll ans = min(mincyc, minpath);
    cout << (ans == M ? -1 : ans) << '\n';
}
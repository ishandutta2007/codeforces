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
#define P(a, n) { cout << "{ "; F(_, 0, n) cout << a[_] << " "; cout << "}" << endl; }
#define EX(x) { cout << x << endl; exit(0); }
#define K first
#define V second
#define M 1000000007 //998244353
#define N 200010

vector<ll> graph[N];
pl d[N];
ll sMx[N], n, m, k;
bool used[N], spec[N];

ll bSearch2(ll l, ll r, ll h) {
    if(l == r) return l;
    ll m = (l + r) / 2;
    return d[m].K >= h ? bSearch2(l, m, h) : bSearch2(m + 1, r, h);
}

bool works(ll m, ll i) {
    if(d[i].V + d[n - 1].K + 1 < m) return false;
    ll mxPos = bSearch2(i + 1, n - 1, m - d[i].V - 1);
    return d[i].K + sMx[mxPos] + 1 >= m;
}

ll bSearch(ll l, ll r, ll i) {
    if(l == r) return l;
    ll m = (l + r + 1) / 2;
    return works(m, i) ? bSearch(m, r, i) : bSearch(l, m - 1, i);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    F(i, 0, k) { G(v) spec[v] = true; }
    while(m--) {
        G(u) G(v)
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<pl> bfs = {{1, 0}}; 
    ll idx = -1, dist = 0;
    while(++idx < bfs.size()) if(!used[bfs[idx].K]) {
        ll v = bfs[idx].K, di = bfs[idx].V;
        if(spec[v]) d[v - 1].K = di;
        if(v == n) dist = di;
        used[v] = true;
        for(ll j : graph[v]) bfs.emplace_back(j, di + 1);
    }
    bfs = {{n, 0}};
    idx = -1;
    fill(used, used + N, false);
    ll ans = 0;
    while(++idx < bfs.size()) if(!used[bfs[idx].K]) {
        ll v = bfs[idx].K, di = bfs[idx].V;
        if(spec[v]) d[v - 1].V = di;
        used[v] = true;
        for(ll j : graph[v]) bfs.emplace_back(j, di + 1);
    }
    sort(d, d + n);
    sMx[n - 1] = d[n - 1].V;
    FD(i, n - 2, -1) sMx[i] = max(sMx[i + 1], d[i].V);
    ll maxAdd = 0;
    F(i, 0, n - 1) if(d[i].K + d[i].V) maxAdd = max(maxAdd, bSearch(0, N, i));
    cout << min(maxAdd, dist) << '\n';
}
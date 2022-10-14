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
#define F(i, l, r) for(ll i = l; i < (r); i++)
#define FD(i, r, l) for(ll i = r; i > (l); i--)
#define P(a, n) { cout << "{ "; F(_, 0, n) cout << a[_] << " "; cout << "}\n"; }
#define EX(x) { cout << x << '\n'; exit(0); }
#define A(a) (a).begin(), (a).end()
#define K first
#define V second
#define M 1000000007 //998244353
#define N 1010

vector<pl> graph[N], edges;
ll d[N][N], p[N], a[N], b[N];

void dijk(int s) {
    fill_n(d[s], N + 1, LLONG_MAX);
    d[s][s] = p[s] = 0;
    priority_queue<pl, vector<pl>, greater<pl>> q;
    q.emplace(0, s);
    while (q.size()) {
        ll du = q.top().K, u = q.top().V;
        q.pop();
        if(du == d[s][u]) for(pl e : graph[u]) {
            ll v = e.K, dv = du + e.V;
            if(dv < d[s][v]) d[s][v] = dv, p[v] = u, q.emplace(dv, v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) G(m) G(k)
    while(m--) {
        G(u) G(v) G(w)
        edges.emplace_back(u, v);
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }
    F(i, 0, k) cin >> a[i] >> b[i];
    F(i, 1, n + 1) dijk(i);
    ll ans = LLONG_MAX;
    for(pl e : edges) {
        ll temp = 0;
        F(i, 0, k) temp += min({d[a[i]][b[i]], d[a[i]][e.K] + d[e.V][b[i]], d[a[i]][e.V] + d[e.K][b[i]]});
        ans = min(ans, temp);
    }
    cout << ans << '\n';
}
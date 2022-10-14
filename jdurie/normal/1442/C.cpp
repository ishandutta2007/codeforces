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
#define M 998244353ll
#define N 200010

ll n, m;
vector<pl> xgraph[2 * N];
vector<pl> ygraph[25 * N];
ll xd[2 * N], yd[25 * N];

ll xdijk() {
    fill_n(xd, 2 * N, LLONG_MAX);
    xd[1] = 0;
    priority_queue<pl, vector<pl>, greater<pl>> q;
    q.emplace(0, 1);
    while (q.size()) {
        ll du = q.top().K, u = q.top().V;
        q.pop();
        if(du == xd[u]) for(pl e : xgraph[u]) {
            ll v = e.K, dv = du + e.V;
            if(dv < xd[v]) xd[v] = dv, q.emplace(dv, v);
        }
    }
    return min(xd[n], xd[n + N]);
}

ll ydijk() {
    fill_n(yd, 25 * N, LLONG_MAX);
    yd[1] = 0;
    priority_queue<pl, vector<pl>, greater<pl>> q;
    q.emplace(0, 1);
    while (q.size()) {
        ll du = q.top().K, u = q.top().V;
        q.pop();
        if(du == yd[u]) for(pl e : ygraph[u]) {
            ll v = e.K, dv = du + e.V;
            if(dv < yd[v]) yd[v] = dv, q.emplace(dv, v);
        }
    }
    ll mn = yd[n];
    F(i, 1, 25) mn = min(mn, yd[n + i * N]);
    return mn;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    while(m--) {
        G(u) G(v)
        xgraph[u].emplace_back(v, 1);
        xgraph[N + v].emplace_back(N + u, 1);
        F(i, 0, 25) 
            if(i & 1) ygraph[v + i * N].emplace_back(u + i * N, 1);
            else ygraph[u + i * N].emplace_back(v + i * N, 1);
    }
    F(i, 1, n + 1) {
        xgraph[i].emplace_back(N + i, M), xgraph[N + i].emplace_back(i, M);
        F(j, 0, 24) ygraph[i + j * N].emplace_back(i + (j + 1) * N, (1 << j));
    }
    ll ans = xdijk();
    if(ans > 25 * M) {
        ll swps = ans / M;
        ans %= M;
        ll p = 1;
        F(j, 0, swps) { ans = (ans + p) % M; p = p * 2 % M; }
        cout << ans << '\n';
    } else cout << ydijk();
}
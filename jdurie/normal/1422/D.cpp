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
#define N 200020
#define Y 100010

vector<pl> graph[N];
ll d[N], p[N];

void dijk(int s) {
    fill_n(d, N, LLONG_MAX);
    d[s] = p[s] = 0;
    priority_queue<pl, vector<pl>, greater<pl>> q;
    q.emplace(0, s);
    while (q.size()) {
        ll du = q.top().K, u = q.top().V;
        q.pop();
        if(du == d[u]) for(pl e : graph[u]) {
            ll v = e.K, dv = du + e.V;
            if(dv < d[v]) d[v] = dv, p[v] = u, q.emplace(dv, v);
        }
    }
}

#define ADD_EDGE(u, v, w) graph[u].emplace_back(v, w), graph[v].emplace_back(u, w);
pl x[N], y[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) G(m) G(sx) G(sy) G(fx) G(fy)
    ADD_EDGE(0, Y, abs(sx - fx) + abs(sy - fy))
    F(i, 1, m + 1) {
        cin >> x[i].K >> y[i].K;
        x[i].V = y[i].V = i;
        ADD_EDGE(i, i + Y, 0)
        ADD_EDGE(0, i, min(abs(sx - x[i].K), abs(sy - y[i].K)))
        ADD_EDGE(Y, i, abs(fx - x[i].K) + abs(fy - y[i].K))
    }
    sort(x + 1, x + m + 1), sort(y + 1, y + m + 1);
    F(i, 1, m) {
        ADD_EDGE(x[i].V, x[i + 1].V, x[i + 1].K - x[i].K)
        ADD_EDGE(y[i].V + Y, y[i + 1].V + Y, y[i + 1].K - y[i].K)
    }
    dijk(0);
    cout << d[Y] << '\n';
}
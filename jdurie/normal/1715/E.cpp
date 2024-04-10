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
#define N 100010

struct seg { ld x; ll m, b; };
vector<seg> hull;

void insert(ll m, ll b) { //lines inserted in inc. slope order for maxhull, dec. for minhull
	while(hull.size()) {
		seg s = hull.back();
		if(s.b + s.m * s.x < b + m * s.x) { //< for minhull
			if(s.m - m) hull.push_back({(b - s.b) / (ld)(s.m - m), m, b});
			return;
		}
		hull.pop_back();
	}
	hull = {{LLONG_MIN, m, b}};
}

ll query(ll x) {
	seg s = *--upper_bound(A(hull), x, [](ll a, seg b) { return a < b.x; });
	return s.b + s.m * x;
}

vector<pl> graph[N];
ll n, d[N];

void dijk() {
    priority_queue<pl, vector<pl>, greater<pl>> q;
    F(i, 1, n + 1) if(d[i] - LLONG_MAX) q.emplace(d[i], i);
    while(q.size()) {
        ll du = q.top().K, u = q.top().V;
        q.pop();
        if(du == d[u]) for(pl e : graph[u]) {
            ll v = e.K, dv = du + e.V;
            if(dv < d[v]) d[v] = dv, q.emplace(dv, v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fill_n(d, N, LLONG_MAX);
    d[1] = 0;
    cin >> n; G(m) G(k)
    while(m--) {
        G(u) G(v) G(w)
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }
    dijk();
    F(i, 0, k) {
        hull.clear();
        F(v, 1, n + 1) if(d[v] - LLONG_MAX) insert(-2 * v, d[v] + v * v);
        F(u, 1, n + 1) d[u] = u * u + query(u);
        dijk();
    }
    F(i, 1, n + 1) cout << d[i] << ' ';
    cout << '\n';
}
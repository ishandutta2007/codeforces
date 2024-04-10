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

set<ll> verts;
map<ll, ll> col;
ll pw(ll a, ll p) { return p ? pw(a * a % M, p / 2) * (p & 1 ? a : 1) % M : 1; }

map<pl, ll> dp;
ll r(ll i, ll c) {
    if(dp.count({i, c})) return dp[{i, c}];
    if(col.count(i) && col[i] - c) return 0;
    dp[{i, c}] = 1;
    F(k, 0, 2) if(verts.count(2 * i + k)) {
        ll z1 = 0;
        F(j, 0, 6) if(j - c && (j ^ c) - 1) z1 = (z1 + r(2 * i + k, j));
        dp[{i, c}] = (dp[{i, c}] * z1) % M;
    }
    return dp[{i, c}];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string c = "rogbwy";
    G(k) G(m)
    while(m--) {
        G(v) GS(t)
        ll id = 0; while(c[id] - t[0]) id++;
        col[v] = id;
        while(v) verts.insert(v), v /= 2;
    }
    ll ans = 0;
    F(i, 0, 6) ans = (ans + r(1, i)) % M;
    cout << ans * pw(4, (1ll << k) - 1 - verts.size()) % M;
}
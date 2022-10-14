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

typedef int ll;
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
#define N 1010

vector<ll> jmps[N];
ll dist[N][N], dp[N][12 * N], n, b[N], c[N];

#define DT dist[i][j]
ll s(ll i, ll j) {
    if(i == j) return 0;
    if(~DT) return DT;
    DT = M;
    for(ll x : jmps[i]) if(i + x <= j) DT = min(DT, 1 + s(i + x, j));
    return DT;
}

#define DP dp[i][k]
ll r(ll i, ll k) {
    if(i == n) return 0;
    if(~DP) return DP;
    DP = r(i + 1, k);
    if(k >= s(1, b[i])) DP = max(DP, c[i] + r(i + 1, k - s(1, b[i])));
    return DP;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dist, -1, sizeof dist);
    F(i, 1, N) F(j, 1, i + 1) if(jmps[i].empty() || i / j - jmps[i].back()) jmps[i].push_back(i / j);
    G(tc) while(tc--) {
        cin >> n; G(k)
        F(i, 0, n) fill_n(dp[i], 12 * n + 1, -1);
        F(i, 0, n) cin >> b[i];
        F(i, 0, n) cin >> c[i];
        cout << r(0, min(k, 12 * n)) << '\n';
    }
}
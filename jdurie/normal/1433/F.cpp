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

typedef int ll;
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
#define M (INT_MIN / 100)
#define N 72

ll n, m, k, a[N][N], dp[N][N][N][N / 2], mxv[N][N], dp2[N][N];

#define DP dp[i][j][md][t]
ll r(ll i, ll j, ll md, ll t) {
    if(j < 0) return md == 0 ? 0 : M;
    if(~DP) return DP;
    DP = r(i, j - 1, md, t);
    if(t) DP = max(DP, a[i][j] + r(i, j - 1, (md - (a[i][j] % k) + k) % k, t - 1));
    if(DP < 0) DP = M;
    return DP;
}

#define DP2 dp2[i][md]
ll r2(ll i, ll md) {
    if(i < 0) return md == 0 ? 0 : M;
    if(~DP2) return DP2;
    DP2 = M;
    F(j, 0, k) DP2 = max(DP2, r2(i - 1, (md - j + k) % k) + mxv[i][j]);
    if(DP2 < 0) DP2 = M;
    return DP2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dp, -1, sizeof dp);
    memset(dp2, -1, sizeof dp2);
    cin >> n >> m >> k;
    F(i, 0, n) F(j, 0, m) cin >> a[i][j];
    F(i, 0, n) F(md, 0, k) mxv[i][md] = r(i, m - 1, md, m / 2);
    cout << r2(n - 1, 0) << '\n';
}
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
#define N 110

ll dp[N][N][N], ncr[N][N], f[N], k, M;

#define DP dp[v][n][q]
ll r(ll v, ll n, ll q) {
    if(~DP) return DP;
    if(!n && !q) return 1;
    if(!n) return 0;
    if(q > (n + 1) / 2) return 0;
    if(v == k) {
        if(q == 1) return f[n];
        return 0;
    }
    DP = 0;
    F(i, 0, q + 1) F(j, 0, n) DP = (DP + ncr[n - 1][j] * r(v + 1, j, i) % M * r(v + 1, n - 1 - j, q - i) % M) % M;
    return DP;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dp, -1, sizeof dp);
    G(n) cin >> k; G(m) cin >> M;
    f[0] = 1;
    F(i, 1, N) f[i] = i * f[i - 1] % M;
    ncr[0][0] = 1;
    F(i, 1, N) {
        ncr[i][0] = 1;
        F(j, 1, i + 1) ncr[i][j] = (ncr[i - 1][j - 1] + ncr[i - 1][j]) % M;
    }
    cout << r(1, n, m) << '\n';
}
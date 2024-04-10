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
#define P(a, n) { cout << "{ "; F(_, 0, n) cout << a[_] << " "; cout << "}\n"; }
#define EX(x) { cout << x << '\n'; exit(0); }
#define A(x) (x).begin(), (x).end()
#define K first
#define V second
#define M 1000000007 //998244353
#define N 210

ll dp[N][N][N];
vector<ll> rs, gs, bs;

#define DP dp[r][g][b]
ll R(ll r, ll g, ll b) {
    if(~DP) return DP;
    DP = 0;
    if(r && g) DP = max(DP, R(r - 1, g - 1, b) + rs[r - 1] * gs[g - 1]);
    if(r && b) DP = max(DP, R(r - 1, g, b - 1) + rs[r - 1] * bs[b - 1]);
    if(b && g) DP = max(DP, R(r, g - 1, b - 1) + bs[b - 1] * gs[g - 1]);
    return DP;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dp, -1, sizeof dp);
    G(rn) G(gn) G(bn)
    F(i, 0, rn) { G(x) rs.push_back(x); }
    F(i, 0, gn) { G(x) gs.push_back(x); }
    F(i, 0, bn) { G(x) bs.push_back(x); }
    sort(A(rs)); sort(A(gs)); sort(A(bs));
    cout << R(rn, gn, bn) << '\n';
}
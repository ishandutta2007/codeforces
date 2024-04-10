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
#define N 2010
#define GOOD(x) (x >= l && x <= r)

ll n, H, l, r, dp[N][N], a[N];

#define DP dp[i][h]
ll rr(ll i, ll h) {
    if(i == n) return 0;
    if(~DP) return DP;
    ll ct1 = rr(i + 1, (h + a[i]) % H);
    if(GOOD((h + a[i]) % H)) ct1++;
    ll ct2 = rr(i + 1, (h + a[i] - 1) % H);
    if(GOOD((h + a[i] - 1) % H)) ct2++;
    return DP = max(ct1, ct2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dp, -1, sizeof dp);
    cin >> n >> H >> l >> r;
    F(i, 0, n) cin >> a[i];
    cout << rr(0, 0) << '\n';
}
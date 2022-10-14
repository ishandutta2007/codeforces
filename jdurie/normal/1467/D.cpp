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
#define N 5010

ll n, ct[N], a[N], dp[N][N];

#define DP dp[i][j]
ll r(ll i, ll j) {
    if(i < 1 || i > n) return 0;
    if(!j) return DP = 1;
    if(~DP) return DP;
    return DP = (r(i - 1, j - 1) + r(i + 1, j - 1)) % M;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dp, -1, sizeof dp);
    cin >> n; G(k) G(q)
    F(i, 1, n + 1) cin >> a[i];
    F(i, 1, n + 1) F(j, 0, k + 1) ct[i] = (ct[i] + r(i, j) * r(i, k - j)) % M;
    ll cur = 0;
    F(i, 1, n + 1) cur = (cur + a[i] * ct[i]) % M;
    while(q--) {
        G(i) G(x)
        cur = (cur + M - a[i] * ct[i] % M) % M;
        a[i] = x;
        cur = (cur + a[i] * ct[i]) % M;
        cout << cur << '\n';
    }
}
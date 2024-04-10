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
#define P(a, n) { cout << "{ "; F(_, 0, n) cout << a[_] << " "; cout << "}" << endl; }
#define EX(x) { cout << x << endl; exit(0); }
#define K first
#define V second
#define M 998244353
#define N 100010

ll dp[64][2], odds, evens;

ll r(ll k, ll o) {
    if(!k) return o ? odds : evens;
    if(dp[k][o]) return dp[k][o];
    if(o) return dp[k][o] = 2 * r(k - 1, 0) * r(k - 1, 1) % M;
    return dp[k][o] = (r(k - 1, 0) * r(k - 1, 0) % M + r(k - 1, 1) * r(k - 1, 1) % M) % M;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    G(n) G(m) G(L) G(R)
    odds = (R + 1) / 2 - L / 2;
    evens = R / 2 - (L - 1) / 2;
    ll ansO = 0, ansE = 1;
    F(j, 0, 64) if(((n * m) >> j) & 1) {
        ll tempO = ansO, tempE = ansE;
        ansO = (tempO * r(j, 0) % M + tempE * r(j, 1) % M) % M;
        ansE = (tempO * r(j, 1) % M + tempE * r(j, 0) % M) % M;
    }
    ll ans = (n * m) % 2 ? (ansO + ansE) % M : ansE;
    cout << ans << '\n';
}
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
#define N 1000010

ll dp[N][8], mask[N], mxb;

bool oddsum(ll mk1, ll mk2) {
    return (__builtin_popcount(mk1) + __builtin_popcount(mk2)) & 1;
}

bool ok(ll mk1, ll mk2) {
    if(mxb == 2) return oddsum(mk1, mk2);
    ll lm1 = mk1 - (mk1 & 1), rm1 = mk1 % 4;
    ll lm2 = mk2 - (mk2 & 1), rm2 = mk2 % 4;
    return oddsum(lm1, lm2) && oddsum(rm1, rm2);
}

#define DIFF(m1, m2) __builtin_popcount(m1 ^ m2)
#define DP dp[i][mk]
ll r(ll i, ll mk) {
    if(~DP) return DP;
    if(!i) return DP = DIFF(mk, mask[i]);
    DP = LLONG_MAX;
    F(x, 0, (1 << mxb)) if(ok(mk, x))
        DP = min(DP, DIFF(mk, mask[i]) + r(i - 1, x));
    return DP;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dp, -1, sizeof dp);
    G(n) G(m)
    mxb = min(n, m);
    if(mxb >= 4) EX(-1)
    if(mxb == 1) EX(0)
    F(i, 0, n) {
        GS(s)
        F(j, 0, m) if(s[j] == '1') {
            if(n < m) mask[j] |= (1 << i);
            else mask[i] |= (1 << j);
        }
    }
    ll ans = LLONG_MAX;
    F(i, 0, (1 << mxb)) ans = min(ans, r(max(n, m) - 1, i));
    cout << ans << '\n';
}
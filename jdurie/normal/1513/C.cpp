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
#define N 200010

ll dp[N][10];

#define DP dp[i][d]
ll r(ll i, ll d) {
    if(~DP) return DP;
    if(i == 0) return DP = 1;
    if(d == 9) return DP = (r(i - 1, 0) + r(i - 1, 1)) % M;
    return DP = r(i - 1, d + 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dp, -1, sizeof dp);
    G(tc) while(tc--) {
        GS(n) G(m)
        ll ans = 0;
        for(char c : n) ans = (ans + r(m, c - '0')) % M;
        cout << ans << '\n';
    }
}
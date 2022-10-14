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
#define N 110
#define Z 10010

ll a[N], b[N], s[N], dp[N][Z];

#define DP dp[i][sa]
ll r(ll i, ll sa) {
    if(min(i, sa) < 0) return sa ? 1e15 : 0;
    if(~DP) return DP;
    DP = 1e15;
    ll sb = s[i] - (sa - a[i]);
    if(sb >= 0 && sa >= a[i]) DP = min(DP, r(i - 1, sa - a[i]) + (sa - a[i]) * a[i] + sb * b[i]);
    sb = s[i] - (sa - b[i]);
    if(sb >= 0 && sa >= b[i]) DP = min(DP, r(i - 1, sa - b[i]) + (sa - b[i]) * b[i] + sb * a[i]);
    return DP;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        memset(dp, -1, sizeof dp);
        G(n)
        F(i, 0, n) cin >> a[i];
        F(i, 0, n) cin >> b[i];
        F(i, 1, n) s[i] = a[i - 1] + b[i - 1] + s[i - 1];
        ll ans = LLONG_MAX;
        F(i, 0, Z) ans = min(ans, r(n - 1, i));
        ans *= 2;
        F(i, 0, n) ans += (n - 1) * (a[i] * a[i] + b[i] * b[i]);
        cout << ans << '\n';
    }
}
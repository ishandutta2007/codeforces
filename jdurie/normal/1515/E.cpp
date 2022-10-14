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
#define N 410
#define NCR(n, r) (f[n] * fi[r] % M * fi[(n) - (r)] % M)

ll f[N], fi[N], dp[N][N], dp2[N][3], n, M;

ll inv(ll a, ll b = M) { return 1 < a ? b - inv(b % a, a) * b / a : 1; }

#define DP2 dp2[i][e]
ll r2(ll i, ll e) {
    if(i == 0) return DP2 = 1;
    if(~DP2) return DP2;
    if(i == 1 && e == 2) return DP2 = 0;
    DP2 = 0;
    F(k, 0, i) DP2 = (DP2 + NCR(i - 1, k) * r2(k, e / 2 + 1) % M * r2(i - 1 - k, (e + 1) / 2 + 1)) % M;
    return DP2;
}

#define DP dp[i][c]
ll r(ll i, ll c) {
    if(c < i / 2 + 1) return DP = 0;
    if(c > i) return DP = 0;
    if(~DP) return DP;
    if(i == c) return DP = r2(i, 0);
    DP = 0;
    F(k, 1, i - 1) if(k <= c) DP = (DP + NCR(c, k) * r2(k, 0) % M * r(i - k - 1, c - k)) % M;
    return DP;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dp, -1, sizeof dp);
    memset(dp2, -1, sizeof dp2);
    cin >> n >> M;
    f[0] = fi[0] = 1;
    F(i, 1, N) f[i] = i * f[i - 1] % M, fi[i] = inv(f[i]);
    ll ans = 0;
    F(i, 1, n + 1) ans = (ans + r(n, i)) % M;
    cout << ans << '\n';
}
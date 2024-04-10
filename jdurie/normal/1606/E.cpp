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
#define M 998244353
#define N 510
#define NCR(n, r) (f[n] * fi[r] % M * fi[(n) - (r)] % M)

ll x, dp[N][N], f[N], fi[N];

ll pw(ll a, ll p) { return p ? pw(a * a % M, p / 2) * (p & 1 ? a : 1) % M : 1; }

ll inv(ll a, ll b = M) { return 1 < a ? b - inv(b % a, a) * b / a : 1; } //inv a mod b

#define DP dp[mx][n]
ll r(ll mx, ll n) {
    if(~DP) return DP;
    if(n == 1) return DP = 1;
    if(mx <= n - 1) return DP = 0;
    DP = 0;
    F(m, 0, n) DP = (DP + pw(min(x, n - 1), m) * NCR(n, m) % M * r(mx - n + 1, n - m) % M) % M;
    return DP;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    f[0] = fi[0] = 1;
    F(i, 1, N) f[i] = i * f[i - 1] % M, fi[i] = inv(f[i]);
    memset(dp, -1, sizeof dp);
    G(n) cin >> x;
    ll ans = pw(x, n);
    F(mx, 1, x + 1) ans = (ans + M - r(mx, n)) % M;
    cout << ans << '\n';
}
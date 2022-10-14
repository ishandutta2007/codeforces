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
#define N 100010
#define NCR(n, r) (f[n] * fi[r] % M * fi[(n) - (r)] % M)

ll f[N], fi[N];

ll inv(ll a, ll b = M) { return 1 < a ? b - inv(b % a, a) * b / a : 1; } //inv a mod b

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    f[0] = fi[0] = 1;
    F(i, 1, N) f[i] = i * f[i - 1] % M, fi[i] = inv(f[i]);
    G(n)
    ll wl = 0, ql = 0, wr = 0, qr = 0;
    ll canbw = 1, canwb = 1, z = 1;
    F(i, 0, n) {
        GS(s)
        if(s[0] == 'W') wl++; else if(s[0] == '?') ql++;
        if(s[1] == 'W') wr++; else if(s[1] == '?') qr++;
        if(s[0] == 'B' || s[1] == 'W') canwb = 0;
        if(s[0] == 'W' || s[1] == 'B') canbw = 0;
        if(s[0] == s[1] && s[0] - '?') z = 0;
        if(s[0] == s[1] && s[0] == '?') z = 2 * z % M;
    }
    ll ans = (canwb + canbw + M - z) % M;
    F(wp, 0, ql + 1) {
        ll wp2 = n - wl - wp - wr;
        if(wp2 >= 0 && wp2 <= qr) ans = (ans + NCR(ql, wp) * NCR(qr, wp2)) % M;
    }
    cout << ans << '\n';
}
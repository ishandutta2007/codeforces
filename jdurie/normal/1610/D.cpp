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
#define L 40
#define NCR(n, r) (f[n] * fi[r] % M * fi[(n) - (r)] % M)

ll ct[L], p2[N], f[N], fi[N];

ll inv(ll a, ll b = M) { return 1 < a ? b - inv(b % a, a) * b / a : 1; } //inv a mod b

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    p2[0] = 1;
    F(i, 1, N) p2[i] = 2 * p2[i - 1] % M;
    f[0] = fi[0] = 1;
    F(i, 1, N) f[i] = i * f[i - 1] % M, fi[i] = inv(f[i]);
    G(n)
    F(i, 0, n) { G(x) ct[__builtin_ctzll(x)]++; }
    ll ev = accumulate(ct + 1, ct + L, 0ll);
    ll ans = (p2[n] - p2[ev] + M) % M;
    ll cur = 0;
    FD(i, L - 1, 0) {
        for(ll j = 2; j <= ct[i]; j += 2) ans = (ans + NCR(ct[i], j) * p2[cur]) % M;
        cur += ct[i];
    }
    cout << ans << '\n';
}
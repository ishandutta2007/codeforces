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
#define S 60

ll n, m, l[S], r[S], nl[S], nr[S], dpold[N], dpnew[N];

ll solve(ll z) {
    ll nm = m / z;
    F(i, 0, n) {
        nl[i] = (l[i] + z - 1) / z, nr[i] = r[i] / z;
        if(nl[i] > nr[i]) return 0;
        nm -= nl[i], nr[i] -= nl[i];
    }
    if(nm < 0) return 0;
    fill_n(dpold, nm + 1, 1);
    F(i, 0, n) {
        ll cur = 0;
        F(s, 0, nm + 1) {
            cur = (cur + dpold[s]) % M;
            if(s > nr[i]) cur = (cur + M - dpold[s - nr[i] - 1]) % M;
            dpnew[s] = cur;
        }
        copy_n(dpnew, nm + 1, dpold);
    }
    return dpold[nm];
}

ll sqf(ll a) {
    ll num = 0;
    for(ll x = 2; x * x <= a; ++x) if(!(a % x)) {
        if(!(a % (x * x))) return 0;
        num++, a /= x;
    }
    if(a > 1) num++;
    return num & 1 ? -1 : 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    F(i, 0, n) cin >> l[i] >> r[i];
    ll ans = 0;
    F(i, 1, m + 1) {
        ll v = sqf(i);
        if(v) ans = (ans + M + v * solve(i)) % M;
    }
    cout << ans << '\n';
}
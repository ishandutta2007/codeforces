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
//#define N 200010

ll k, d, t;

bool works(ld m) {
    ld cyc = floor(m / d);
    ld mon = cyc * k, moff = cyc * (d - k);
    ld extr = m - d * floor(m / d);
    mon += min((ld)k, extr);
    moff += extr - min((ld)k, extr);
    return moff + 2 * mon >= 2 * t;
}

ll iter = 0;
ld bsch(ld l, ld r) {
    if(iter++ == 6000) return l;
    ld m = (l + r) / 2;
    return works(m) ? bsch(l, m) : bsch(m, r);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> k >> d >> t;
    d *= (k + d - 1) / d;
    cout << fixed << setprecision(10) << bsch(0, 2e18) << '\n';
}
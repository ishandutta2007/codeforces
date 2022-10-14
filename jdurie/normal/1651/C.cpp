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

ll a[N], b[N];



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n) set<ll> sa, sb;
        F(i, 0, n) cin >> a[i];
        F(i, 0, n) cin >> b[i];
        ll xa0 = abs(a[0] - b[0]), xan = abs(a[n - 1] - b[0]);
        F(i, 1, n) xa0 = min(xa0, abs(a[0] - b[i])), xan = min(xan, abs(a[n - 1] - b[i]));
        ll xb0 = abs(b[0] - a[0]), xbn = abs(b[n - 1] - a[0]);
        F(i, 1, n) xb0 = min(xb0, abs(b[0] - a[i])), xbn = min(xbn, abs(b[n - 1] - a[i]));
        ll d00 = abs(a[0] - b[0]), d0n = abs(a[0] - b[n - 1]), dn0 = abs(a[n - 1] - b[0]), dnn = abs(a[n - 1] - b[n - 1]);
        cout << min({xa0 + xan + xb0 + xbn,
        d00 + dnn, dn0 + d0n,
        d00 + xan + xbn, d0n + xan + xb0,
        dn0 + xa0 + xbn, dnn + xa0 + xb0}) << '\n';
    }
}
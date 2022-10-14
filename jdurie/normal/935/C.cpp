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
#define N 100010
#define EPS 0.0000001

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    GD(r) GD(x1) GD(y1) GD(x2) GD(y2)
    x2 -= x1, y2 -= y1;
    if(x2 * x2 + y2 * y2 >= r * r) cout << fixed << setprecision(10) << x1 << ' ' << y1 << ' ' << r << '\n';
    else if(abs(x2) < EPS && abs(y2) < EPS) cout << fixed << setprecision(10) << x1 << ' ' << y1 + r / 2. << ' ' << r / 2 << '\n';
    else {
        ld oX = -x2, oY = -y2, d = sqrt(x2 * x2 + y2 * y2);
        ld R = (r + d) / 2.;
        oX *= (R - d) / d, oY *= (R - d) / d;
        cout << fixed << setprecision(10) << x1 + oX << ' ' << y1 + oY << ' ' << R << '\n';
    }
}
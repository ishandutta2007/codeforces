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
//#define N 100010

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(x) G(y) G(a) G(b)
        if(x > y) swap(x, y);
        if(a > b) swap(a, b);
        if(a == b) cout << x / a << '\n';
        else {
            ll z = min({x / a, y / b, (y - x) / (b - a)});
            x -= z * a; y -= z * b;
            ll z2 = min(x, y) / (a + b);
            x -= z2 * (a + b); y -= z2 * (a + b);
            ll z3 = 0;
            if(x >= a && y >= b) z3++;
            else if(x >= b && y >= a) z3++;
            cout << z + 2 * z2 + z3 << '\n';
        }
    }
}
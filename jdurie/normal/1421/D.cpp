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
#define F(i, l, r) for(ll i = l; i < (r); i++)
#define FD(i, r, l) for(ll i = r; i > (l); i--)
#define P(a, n) { cout << "{ "; F(_, 0, n) cout << a[_] << " "; cout << "}\n"; }
#define EX(x) { cout << x << '\n'; exit(0); }
#define A(a) (a).begin(), (a).end()
#define K first
#define V second
#define M 1000000007 //998244353
#define N 100010

ll c[6];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(y) G(x)
        F(i, 0, 6) cin >> c[i];
        if(y < 0) {
            y *= -1; x *= -1;
            F(j, 0, 3) swap(c[j], c[j + 3]);
        }
        F(i, 0, 100) F(j, 0, 6) c[j] = min(c[j], c[(j + 1) % 6] + c[(j + 5) % 6]);
        if(x <= 0) cout << y * c[5] - x * c[4] << '\n';
        else if(x < y) cout << x * c[0] + (y - x) * c[5] << '\n';
        else cout << y * c[0] + (x - y) * c[1] << '\n';
    }
}
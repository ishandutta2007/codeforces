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
#define P(a, n) { cout << "{ "; F(_, 0, n) cout << a[_] << " "; cout << "}" << endl; }
#define EX(x) { cout << x << endl; goto eotc; }
#define K first
#define V second
#define M 1000000007 //998244353
#define N 100010

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    G(T) while(T--) {
        GD(h) GD(c) GD(t)
        ld a = (h + c) / 2;
        if(t <= a) cout << "2\n";
        else if(t >= h) cout << "1\n";
        else {
            ld k = (h - t) / (t - a);
            ll d = (ll)ceil(k), f = (ll)floor(k);
            if(d % 2) d++; if(f % 2) f--;
            if(abs(t - (d * a + h) / (d + 1)) < abs(t - (f * a + h) / (f + 1))) cout << d + 1 << '\n';
            else cout << f + 1 << '\n';
        }
    }   
}
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
#define EX(x) { cout << x << endl; exit(0); }
#define K first
#define V second
#define M 1000000007 //998244353
#define N 100010

ll minDig(ll a) {
    ll mn = 10;
    while(a) {
        mn = min(mn, a % 10);
        a /= 10;
    }
    return mn;
}

ll maxDig(ll a) {
    ll mx = 0;
    while(a) {
        mx = max(mx, a % 10);
        a /= 10;
    }
    return mx;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    G(T) while(T--) {
        G(a) G(k)
        while(minDig(a) && --k) 
            a += minDig(a) * maxDig(a);
        cout << a << '\n';
    }
}
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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n) GS(s)
        ll last0 = -1;
        F(i, 0, n) if(s[i] == '0') last0 = i;
        bool seen1 = false, done0 = false;
        F(i, 0, n) {
            if(s[i] == '1') seen1 = true;
            if(s[i] == '0' && seen1 && !done0) {
                cout << '0'; done0 = true;
            }
            if(s[i] == '0' && !seen1) cout << '0';
            if(s[i] == '1' && i > last0) cout << '1';
        }
        cout << '\n';
    }
}
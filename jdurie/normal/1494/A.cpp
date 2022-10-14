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

string do_tc(string s) {
    ll n = s.size();
    if(s[0] == s.back()) return "NO\n";
    ll c0 = count(A(s), s[0]);
    ll c2 = count(A(s), s.back());
    if(n % 2 || (c0 - n / 2 && c2 - n / 2)) return "NO\n";
    if(c0 == n / 2) {
        ll cr = 0;
        for(char c : s) {
            if(c == s[0]) cr++;
            else cr--;
            if(cr < 0) return "NO\n";
        }
        if(cr) return "NO\n";
        else return "YES\n";
    } else {
        ll cr = 0;
        for(char c : s) {
            if(c - s.back()) cr++;
            else cr--;
            if(cr < 0) return "NO\n";
        }
        if(cr) return "NO\n";
        else return "YES\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        GS(s)
        cout << do_tc(s);
    }    
}
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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n) vector<string> a, b, c;
        map<string, ll> ct;
        F(i, 0, n) { GS(s) a.push_back(s); ct[s]++; }
        F(i, 0, n) { GS(s) b.push_back(s); ct[s]++; }
        F(i, 0, n) { GS(s) c.push_back(s); ct[s]++; }
        ll sc = 0;
        for(string s : a) if(ct[s] == 1) sc += 3; else if(ct[s] == 2) sc++;
        cout << sc << ' ';
        sc = 0;
        for(string s : b) if(ct[s] == 1) sc += 3; else if(ct[s] == 2) sc++;
        cout << sc << ' ';
        sc = 0;
        for(string s : c) if(ct[s] == 1) sc += 3; else if(ct[s] == 2) sc++;
        cout << sc << '\n';
    }
}
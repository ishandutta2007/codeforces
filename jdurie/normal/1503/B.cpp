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

#define DO_POP(k, v) cout << k << ' ' << v.back().K << ' ' << v.back().V << endl, v.pop_back();

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n)
    vector<pl> v1;
    vector<pl> v2;
    F(i, 1, n + 1) F(j, 1, n + 1)
        if((i + j) & 1) v1.emplace_back(i, j);   
        else v2.emplace_back(i, j);
    while(v1.size() || v2.size()) {
        G(a)
        if(v1.size() && v2.size()) {
            if(a == 1) DO_POP(2, v2)
            else DO_POP(1, v1)
        } else if(v1.size()) {
            if(a == 1) DO_POP(3, v1)
            else DO_POP(1, v1)
        } else {
            if(a == 2) DO_POP(3, v2)
            else DO_POP(2, v2)
        }
    }
}
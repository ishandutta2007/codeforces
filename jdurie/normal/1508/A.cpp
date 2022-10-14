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

void solve(string a, string b, ll n, bool z) {
    ll i1 = 0, i2 = 0;
    char pr = z ? '0' : '1';
    char ot = '0' + '1' - pr;
    ll sz = 0;
    while(min(i1, i2) < 2 * n) {
        if(i1 < 2 * n && a[i1] == ot) { cout << ot; i1++; sz++; }
        else if(i2 < 2 * n && b[i2] == ot) { cout << ot; i2++; sz++; }
        else { cout << pr; i1++; i2++; sz++; }
    }
    F(i, 0, 3 * n - sz) cout << "0";
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n) GS(s1) GS(s2) GS(s3)
        ll z1 = count(A(s1), '0'), o1 = s1.size() - z1; 
        ll z2 = count(A(s2), '0'), o2 = s2.size() - z2; 
        ll z3 = count(A(s3), '0'), o3 = s3.size() - z3;   
        bool b1 = z1 > o1, b2 = z2 > o2, b3 = z3 > o3;
        if(b1 == b2) solve(s1, s2, n, b1);
        else if(b1 == b3) solve(s1, s3, n, b1);
        else solve(s2, s3, n, b2); 
    }
}
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

string grid[8];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    F(i, 0, 8) cin >> grid[i];
    ll wans = LLONG_MAX, bans = LLONG_MAX;
    F(i, 0, 8) F(j, 0, 8) 
        if(grid[i][j] == 'W') {
            bool ok = true;
            F(k, 0, i) if(grid[k][j] != '.') ok = false;
            if(ok) wans = min(wans, i);
        } else if(grid[i][j] == 'B') {
            bool ok = true;
            F(k, i + 1, 8) if(grid[k][j] != '.') ok = false;
            if(ok) bans = min(bans, 7 - i);
        }
    cout << (wans <= bans ? "A\n" : "B\n");
}
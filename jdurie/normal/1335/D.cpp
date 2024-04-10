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

ll grid[9][9];

void fix(ll i, ll j) {
    grid[i][j] = (grid[i][j] == 1 ? 2 : 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    G(tc) while(tc--) {
        F(i, 0, 9) {
            GS(s)
            F(j, 0, 9) grid[i][j] = s[j] - '0';
        }
        fix(0, 0); fix(3, 1); fix(6, 2);
        fix(1, 3); fix(4, 4); fix(7, 5);
        fix(2, 6); fix(5, 7); fix(8, 8);
        F(i, 0, 9) {
            F(j, 0, 9) cout << grid[i][j];
            cout << '\n';
        }
    }
}
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
#define N 310

string grid[N];
ll ct[256][3];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        fill_n(ct['X'], 3, 0);
        fill_n(ct['O'], 3, 0);
        G(n) F(i, 0, n) cin >> grid[i];
        ll sq = 0;
        F(i, 0, n) F(j, 0, n) {
            ct[grid[i][j]][(i + j) % 3]++;
            if(grid[i][j] - '.') sq++;
        }
        F(a, 0, 3) F(b, 0, 3) if(a - b && ct['X'][a] + ct['O'][b] <= sq / 3) {
            F(i, 0, n) F(j, 0, n)
                if(grid[i][j] == 'X' && (i + j) % 3 == a) grid[i][j] = 'O';
                else if(grid[i][j] == 'O' && (i + j) % 3 == b) grid[i][j] = 'X';
            goto prgrid;
        }
        prgrid:;
        F(i, 0, n) cout << grid[i] << '\n';
    }
}
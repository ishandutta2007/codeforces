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
#define N 110

ll grid[N][N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n)
    F(s, 1, 2 * n - 1) F(r, 0, s + 1) grid[r][s - r] = r & 1 ? (1ll << (s - 1)) : 0;
    F(i, 0, n) {
        F(j, 0, n) cout << grid[i][j] << ' ';
        cout << endl;
    }
    G(q) while(q--) {
        G(k)
        ll cR = 0, cC = 0;
        vector<pl> path;
        path.emplace_back(1, 1);
        while(cR != n - 1 || cC != n - 1) {
            bool down;
            if(cR == n - 1) down = false;
            else if(cC == n - 1) down = true;
            else {
                ll s = cR + cC;
                if(k & (1ll << s)) down = grid[cR + 1][cC] == (1ll << s);
                else down = grid[cR + 1][cC] == 0;
            }
            if(down) cR++; else cC++;
            path.emplace_back(cR + 1, cC + 1);
        }
        for(pl p : path) cout << p.K << ' ' << p.V << endl;
    }
}
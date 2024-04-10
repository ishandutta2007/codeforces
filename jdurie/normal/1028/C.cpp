#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
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
#define N 140000

ll rect[N][4], extr[4][2];

#define AAA(i, j) extr[j][extr[j][0] == rect[i][j]]

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    G(n)
    extr[0][0] = extr[0][1] = extr[1][0] = extr[1][1] = LLONG_MIN;
    extr[2][0] = extr[2][1] = extr[3][0] = extr[3][1] = LLONG_MAX;
    F(i, 0, n) F(j, 0, 4) {
        cin >> rect[i][j];
        if(j < 2) {
            if(rect[i][j] >= extr[j][0]) {
                extr[j][1] = extr[j][0];
                extr[j][0] = rect[i][j];
            } else if(rect[i][j] >= extr[j][1]) extr[j][1] = rect[i][j];
        } else {
            if(rect[i][j] <= extr[j][0]) {
                extr[j][1] = extr[j][0];
                extr[j][0] = rect[i][j];
            } else if(rect[i][j] <= extr[j][1]) extr[j][1] = rect[i][j];
        }
    }
    F(i, 0, n) {
        ll minX = AAA(i, 0), minY = AAA(i, 1);
        ll maxX = AAA(i, 2), maxY = AAA(i, 3);
        if(minX <= maxX && minY <= maxY) EX(minX << " " << minY)
    }
}
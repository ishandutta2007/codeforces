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
#define N 510

ll gr[N][N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n)
    if(n < 3) EX(-1)
    gr[0][0] = n * n - 2; gr[0][1] = n * n - 3; gr[0][2] = n * n;
    gr[1][0] = n * n - 1; gr[1][1] = n * n - 6; gr[1][2] = n * n - 5;
    gr[2][0] = n * n - 8; gr[2][1] = n * n - 7; gr[2][2] = n * n - 4;
    ll nxt = n * n - 9;
    F(i, 0, n - 3) {
        if(i & 1) {
            F(j, 0, 4 + i) gr[j][3 + i] = nxt--;
            FD(j, 2 + i, -1) gr[3 + i][j] = nxt--;
        } else {
            F(j, 0, 4 + i) gr[3 + i][j] = nxt--;
            FD(j, 2 + i, -1) gr[j][3 + i] = nxt--;
        }
    }
    F(i, 0, n) F(j, 0, n) cout << gr[i][j] << " \n"[j == n - 1];
}
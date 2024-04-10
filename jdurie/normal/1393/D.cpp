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
#define OK(r, c) (r >= 0 && c >= 0 && r < n && c < m)
#define K first
#define V second
#define M 1000000007 //998244353
#define N 2010

ll n, m, ans[N][N];
string grid[N];

bool works(ll r, ll c, ll h) {
    if(!h) return true;
    if(!OK(r + h, c - h) || !OK(r + h, c + h) || !OK(r + 2 * h, c)) return false;
    return  grid[r][c] == grid[r + 1][c] &&
            grid[r][c] == grid[r + 1][c - 1] &&
            grid[r][c] == grid[r + 1][c + 1] &&
            grid[r][c] == grid[r + 2 * h][c] &&
            ans[r + 1][c] >= h - 1 &&
            ans[r + 1][c - 1] >= h - 1 &&
            ans[r + 1][c + 1] >= h - 1;
}

ll bSearch(ll i, ll j, ll l, ll r) {
    if(l == r) return ans[i][j] = l;
    ll h = (l + r + 1) / 2;
    return works(i, j, h) ? bSearch(i, j, h, r) : bSearch(i, j, l, h - 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m; F(i, 0, n) cin >> grid[i];
    ll a = 0;
    FD(r, n - 1, -1) F(c, 0, m) a += bSearch(r, c, 0, n) + 1;
    cout << a << '\n';
}
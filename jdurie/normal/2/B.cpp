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

typedef int ll;
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
#define N 1010

ll grid[N][N], dp[2][N][N], n;
char ch[2][N][N];

ll r(ll i, ll j, ll k) {
    if(i == n || j == n) return INT_MAX;
    if(dp[k][i][j] != -1) return dp[k][i][j];
    ll ct = 0;
    while(grid[i][j] % (3 * k + 2) == 0) {
        if(!grid[i][j]) { ct = 1; break; }
        grid[i][j] /= (3 * k + 2);
        ct++;
    }
    if(i == n - 1 && j == n - 1) return dp[k][i][j] = ct;
    ll rR = r(i, j + 1, k), rD = r(i + 1, j, k);
    ch[k][i][j] = rR < rD ? 'R' : 'D';
    return dp[k][i][j] = min(rR, rD) + ct;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    ll i0 = -1, j0 = -1;
    F(i, 0, n) F(j, 0, n) {
        dp[0][i][j] = dp[1][i][j] = -1;
        cin >> grid[i][j];
        if(!grid[i][j]) { i0 = i; j0 = j; }
    }
    ll k2 = r(0, 0, 0), k5 = r(0, 0, 1);
    if(i0 != -1) k2 = min(1, k2);
    cout << min(k2, k5) << '\n';
    ll i = 0, j = 0, k = k2 < k5 ? 0 : 1;
    if(i0 != -1 && min(k2, k5)) {
        while(i < i0) { cout << 'D'; i++; }
        while(j < j0) { cout << 'R'; j++; }
        while(i < n - 1) { cout << 'D'; i++; }
        while(j < n - 1) { cout << 'R'; j++; }
    } else while(i != n - 1 || j != n - 1) {
        cout << ch[k][i][j];
        if(ch[k][i][j] == 'R') j++; else i++;
    }
    cout << '\n';
}
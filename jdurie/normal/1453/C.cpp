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
#define N 2010

ll n, a[N][N], mnR[10], mxR[10], mnInR[N][10], mxInR[N][10], ans[10];
string grid[N];

void solve() {
    F(i, 0, n) fill_n(mnInR[i], 10, N), fill_n(mxInR[i], 10, 0);
    fill_n(mnR, 10, N), fill_n(mxR, 10, 0);
    F(i, 0, n) F(j, 0, n) {
        mnR[a[i][j]] = min(mnR[a[i][j]], i);
        mxR[a[i][j]] = max(mxR[a[i][j]], i);
        mnInR[i][a[i][j]] = min(mnInR[i][a[i][j]], j);
        mxInR[i][a[i][j]] = max(mxInR[i][a[i][j]], j);
    }
    F(c, 0, 10) F(i, 0, n) if(mnInR[i][c] - N) {
        ll mxd = max(i - mnR[c], mxR[c] - i);
        ll mxb = max(n - mnInR[i][c] - 1, mxInR[i][c]);
        ans[c] = max(ans[c], mxd * mxb);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        fill_n(ans, 10, 0);
        cin >> n;
        F(i, 0, n) cin >> grid[i];
        F(i, 0, n) F(j, 0, n) a[i][j] = grid[i][j] - '0';
        solve();
        F(i, 0, n) F(j, 0, n) a[i][j] = grid[j][i] - '0';
        solve();
        F(i, 0, 10) cout << ans[i] << ' ';
        cout << '\n';
    }
}
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

ll n, k, z, a[N], dp[N][10][2];

#define DP dp[m][y][l]
ll r(ll m, ll y, ll l) {
    if(~DP) return DP;
    if(m == k) return DP = 0;
    ll idx = m - 2 * y;
    DP = a[idx + 1] + r(m + 1, y, 0);
    if(idx && y < z && !l) DP = max(DP, a[idx - 1] + r(m + 1, y + 1, 1));
    return DP;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        cin >> n >> k >> z;
        F(i, 0, n) cin >> a[i];
        F(i, 0, k + 1) F(j, 0, 10) dp[i][j][0] = dp[i][j][1] = -1;
        cout << a[0] + r(0, 0, 0) << '\n';
    }
}
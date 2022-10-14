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
#define N 5010
#define C(x) max(0ll, x - h[i] + 1)
#define D(x) (x >= 0 && x < n ? C(h[x]) : 0)
#define INF 10000000000ll
#define Q(x) (x >= INF ? -1 : x)

ll n, h[N], dp[N][N][2];

ll r(ll i, ll k, ll e) {
    if(!k) return 0;
    if(dp[i][k][e] != -1) return dp[i][k][e];
    if(!k) return dp[i][k][e] = e ? INF : 0;
    if(i < 2 && k > 1) return dp[i][k][e] = INF;
    if(!i) return dp[i][k][e] = e ? D(1) : INF;
    if(i == 1) return dp[i][k][e] = e ? D(0) + D(2) : r(0, 1, 1);
    if(e) {
        ll cost1 = C(h[i - 1]) + r(i - 2, k - 1, 0) + D(i + 1);
        ll cost2 = k > 1 ? C(min(h[i - 1], h[i - 2] - 1)) + r(i - 2, k - 1, 1) + D(i + 1) : cost1;
        return dp[i][k][e] = min(cost1, cost2);
    } else return dp[i][k][e] = min(r(i - 1, k, 0), r(i - 1, k, 1));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    F(i, 0, n) cin >> h[i];
    F(i, 0, N) F(j, 0, N) dp[i][j][0] = dp[i][j][1] = -1;
    F(k, 1, (n + 1) / 2 + 1) cout << min(r(n - 1, k, 0), r(n - 1, k, 1)) << ' ';
    cout << '\n';
}
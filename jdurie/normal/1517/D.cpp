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
#define N 510

ll dp[N][N][30];
vector<pair<pl, ll>> graph[N][N];

#define DP dp[i][j][k]
ll r(ll i, ll j, ll k) {
    if(~DP) return DP;
    if(!k) return DP = 0;
    DP = LLONG_MAX;
    for(auto p : graph[i][j]) DP = min(DP, 2 * p.V + r(p.K.K, p.K.V, k - 2));
    return DP;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dp, -1, sizeof dp);
    G(n) G(m) G(k)
    if(k & 1) {
        F(i, 0, n) F(j, 0, m) cout << "-1" << " \n"[j == m - 1];
        exit(0);
    }
    F(i, 0, n) F(j, 0, m - 1) {
        G(w)
        graph[i][j].push_back({{i, j + 1}, w});
        graph[i][j + 1].push_back({{i, j}, w});
    }
    F(i, 0, n - 1) F(j, 0, m) {
        G(w)
        graph[i][j].push_back({{i + 1, j}, w});
        graph[i + 1][j].push_back({{i, j}, w});
    }
    F(i, 0, n) F(j, 0, m) cout << r(i, j, k) << " \n"[j == m - 1];
}
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
#define N 25
#define SQ(x) ((x) * (x))
#define TS(i) to_string(i + 1)
#define DIST(i, j) (SQ(x[i] - x[j]) + SQ(y[i] - y[j]))

ll n, x[N], y[N];
map<ll, pair<ll, string>> dp;

pair<ll, string> r(ll mask) {
    if(mask == (1 << n) - 1) return {0, "0"};
    if(dp.count(mask)) return dp[mask];
    ll i = 0;
    while(mask & (1 << i)) i++;
    auto temp = r(mask | (1 << i));
    dp[mask].K = 2 * DIST(i, 24) + temp.K;
    dp[mask].V = "0 " + TS(i) + " " + temp.V;
    for(ll j = i + 1; j < n; j++) if(!(mask & (1 << j))) {
        temp = r(mask | (1 << i) | (1 << j));
        ll val = DIST(i, 24) + DIST(i, j) + DIST(j, 24) + temp.K;
        string str = "0 " + TS(i) + " " + TS(j) + " " + temp.V;
        if(val < dp[mask].K) {
            dp[mask].K = val;
            dp[mask].V = str;
        }
    }
    return dp[mask];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> x[24] >> y[24] >> n;
    F(i, 0, n) cin >> x[i] >> y[i];
    cout << r(0).K << '\n' << r(0).V << '\n';
}
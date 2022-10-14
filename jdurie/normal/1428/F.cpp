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
#define F(i, l, r) for(ll i = l; i < (r); i++)
#define FD(i, r, l) for(ll i = r; i > (l); i--)
#define P(a, n) { cout << "{ "; F(_, 0, n) { if(a[_] < 10) cout << ' '; cout << a[_] << " "; }cout << "}\n"; }
#define EX(x) { cout << x << '\n'; exit(0); }
#define A(a) (a).begin(), (a).end()
#define K first
#define V second
#define M 1000000007 //998244353
#define N 500010

ll n, dp[N], contrib[N], mx[N], sz[N], lst[N], lf[N];
string s;

#define EE(i) ((i) * ((i) - 1) / 2)

ll r(ll i) {
    if(~dp[i]) return dp[i];
    if(i == n) return dp[i] = 0;
    if(s[i] == '0') return dp[i] = r(i + 1);
    r(i + contrib[i]);
    if(sz[i] == mx[i]) return dp[i] = (n - i) * sz[i] - EE(sz[i]);
    return dp[i] = r(i + contrib[i] - sz[i]) + (contrib[i] - sz[i]) * sz[i];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dp, -1, sizeof dp);
    cin >> n >> s;
    F(i, 0, n) {
        if(s[i] == '0' || !i || s[i - 1] == '0') lf[i] = i;
        else lf[i] = lf[i - 1];
    }
    ll cur = 0;
    FD(i, n - 1, -1) {
        if(s[i] == '1') cur++;
        else cur = 0;
        sz[i] = cur;
        mx[i] = max(mx[i + 1], cur);
        if(sz[i] == mx[i]) contrib[i] = n - i;
        else if(s[i] == '0') contrib[i] = 0;
        else contrib[i] = lf[lst[cur]] + sz[i] - i;
        lst[cur] = i;
    }
    ll ans = 0;
    F(i, 0, n) ans += r(i);
    cout << ans << '\n';
}
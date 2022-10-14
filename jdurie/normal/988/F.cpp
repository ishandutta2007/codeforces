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

ll a, n, m, dp[N];
map<ll, ll> mp;
set<ll> sus;

ll r(ll i) {
    if(i < 0) return 0;
    if(~dp[i]) return dp[i];
    if(!sus.count(i)) return dp[i] = r(i - 1);
    dp[i] = LLONG_MAX / 10;
    for(pl p : mp) if(p.K <= i) dp[i] = min(dp[i], (i - p.K + 1) * p.V + r(p.K - 1));
    return dp[i];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dp, -1, sizeof dp);
    cin >> a >> n >> m;
    while(n--) { G(l) G(r) F(j, l, r) sus.insert(j); }
    while(m--) { G(x) G(p) if(!mp.count(x)) mp[x] = p; else mp[x] = min(mp[x], p); }
    ll ans = r(a);
    cout << (ans == LLONG_MAX / 10 ? -1 : ans) << '\n';
}
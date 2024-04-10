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
#define WT first
#define DP second
#define M 1000000007 //998244353
#define N 100010

set<pl> gout[N];
ll u[N], v[N], w[N], dp[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) G(m)
    F(i, 0, m) cin >> u[i] >> v[i] >> w[i];
    FD(i, m - 1, -1) {
        auto it = gout[v[i]].upper_bound({w[i], M});
        if(it == gout[v[i]].end()) dp[i] = 1;
        else dp[i] = 1 + it->DP;
        while(!gout[u[i]].empty() && gout[u[i]].begin()->WT <= w[i]) {
            pl p = *--gout[u[i]].upper_bound({w[i], M});
            if(p.DP <= dp[i]) gout[u[i]].erase(p);
            else break;
        }
        it = gout[u[i]].upper_bound({w[i], M});
        if(it == gout[u[i]].end() || it->DP < dp[i]) gout[u[i]].insert({w[i], dp[i]});
    }
    cout << *max_element(dp, dp + m) << '\n';
}
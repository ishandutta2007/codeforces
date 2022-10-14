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
#define M 100000007 //998244353
#define N 260

ll dp[N][N][N], del[N][N], l[N];

#define DP dp[p][s][c]
ll r(ll p, ll s, ll c) {
    if(!s) return p ? M : 0;
    if(p < c) return M;
    if(~DP) return DP;
    return DP = min(r(p, s, c + 1), del[s][p] - del[s][p - c] + r(p - c, s - 1, c));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dp, -1, sizeof dp);
    G(n) G(m) ll idx = 1;
    F(i, 1, n + 1) {
        G(x) while(x--) l[idx++] = i;
    }
    F(s, 1, n + 1) F(i, 1, m + 1) del[s][i] = abs(l[i] - s) + del[s][i - 1];
    ll ans = M;
    F(k, 0, m + 1) ans = min(ans, r(m, n, k));
    cout << ans << '\n';
}
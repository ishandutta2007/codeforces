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
#define N 100010

ll dp[N][2], x[N], h[N], n, m;
pair<pl, pl> l[N];
vector<pl> lbr[N];

#define DP dp[i][q]
ll r(ll i, ll q) {
    if(~DP) return DP;
    DP = LLONG_MAX;
    ll r1 = l[i].K.K, c1 = l[i].K.V, r2 = l[i].V.K, c2 = l[i].V.V;
    if(lbr[r2].size()) {
        if(c2 >= lbr[r2][0].K) {
            pl p = *--upper_bound(A(lbr[r2]), pl{c2, M});
            if(r(p.V, 0) != LLONG_MAX) DP = min(DP, (c2 - p.K) * x[r2] - h[i] + r(p.V, 0));
        }
        if(c2 <= lbr[r2].back().K) {
            pl p = *lower_bound(A(lbr[r2]), pl{c2, 0});
            if(r(p.V, 1) != LLONG_MAX) DP = min(DP, (p.K - c2) * x[r2] - h[i] + r(p.V, 1));
        }
    } else if(r2 == n) DP = min(DP, -h[i] + (m - c2) * x[n]);
    if(q - 1 && lbr[r1][0] != pl{c1, i}) {
        pl p = *--lower_bound(A(lbr[r1]), pl{c1, i});
        if(r(p.V, 0) != LLONG_MAX) DP = min(DP, (c1 - p.K) * x[r1] + r(p.V, 0));
    }
    if(q && lbr[r1].back() != pl{c1, i}) {
        pl p = *upper_bound(A(lbr[r1]), pl{c1, i});
        if(r(p.V, 1) != LLONG_MAX) DP = min(DP, (p.K - c1) * x[r1] + r(p.V, 1));
    }
    return DP;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dp, -1, sizeof dp);
    G(tc) while(tc--) {
        cin >> n >> m; G(k)
        F(i, 1, n + 1) cin >> x[i];
        F(i, 0, k) {
            cin >> l[i].K.K >> l[i].K.V >> l[i].V.K >> l[i].V.V >> h[i];
            lbr[l[i].K.K].emplace_back(l[i].K.V, i);
        }
        F(i, 1, n + 1) sort(A(lbr[i]));
        if(lbr[1].empty()) cout << "NO ESCAPE\n";
        else {
            ll xy = r(lbr[1][0].V, 1);
            if(xy == LLONG_MAX) cout << "NO ESCAPE\n";
            else cout << xy + (lbr[1][0].K - 1) * x[1] << '\n';
        }
        F(i, 1, n + 1) lbr[i].clear();
        F(i, 0, k) dp[i][0] = dp[i][1] = -1;
    }
}
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

typedef int ll;
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
#define N 300010
#define L 20

ll a[N], rmq[N][L], rxq[N][L];

ll mquery(ll l, ll r) { //half open interval [l, r)
    ll k = 63 - __builtin_clzll(r - l);
    return min(rmq[l][k], rmq[r - (1 << k)][k]);
}

ll xquery(ll l, ll r) { //half open interval [l, r)
    ll k = 63 - __builtin_clzll(r - l);
    return max(rxq[l][k], rxq[r - (1 << k)][k]);
}

pl qr(ll l, ll r) { return {mquery(l, r), xquery(l, r)}; }

ll solve(ll l, ll r, ll lv, ll rv) {
    if(l == r) return 0;
    ll m = (l + r) / 2;
    pl p = qr(l, m + 1), q = qr(m + 1, r + 1);
    if(p.V - p.K != m - l || q.V - q.K != r - m - 1) return -1;
    ll s1 = solve(l, m, p.K, p.V), s2 = solve(m + 1, r, q.K, q.V);
    if(~s1 && ~s2) return s1 + s2 + (q.K == lv);
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(m) F(i, 0, m) cin >> a[i]; ll n = m;
        F(i, 0, n) rmq[i][0] = rxq[i][0] = a[i];
        F(j, 1, L) F(i, 0, n) {
            ll i2 = i + (1 << (j - 1));
            if(i2 < n) rmq[i][j] = min(rmq[i][j - 1], rmq[i2][j - 1]);
            else rmq[i][j] = rmq[i][j - 1];
        }
        F(j, 1, L) F(i, 0, n) {
            ll i2 = i + (1 << (j - 1));
            if(i2 < n) rxq[i][j] = max(rxq[i][j - 1], rxq[i2][j - 1]);
            else rxq[i][j] = rxq[i][j - 1];
        }
        cout << solve(0, m - 1, 1, m) << '\n';
    }
}
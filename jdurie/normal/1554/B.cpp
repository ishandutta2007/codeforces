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
#define N 200010
#define L 20

pl dp[N];
ll a[N];
vector<ll> ind[N];

void remax(ll msk, ll x) {
    if(x > dp[msk].K) dp[msk] = {x, dp[msk].K};
    else if(x < dp[msk].K && x > dp[msk].V) dp[msk].V = x;
}

pl r(ll msk) {
    if(~dp[msk].K) return dp[msk];
    dp[msk] = {0, 0};
    for(ll x : ind[msk]) remax(msk, x);
    F(i, 0, L) if((msk >> i) & 1) {
        pl q = r(msk ^ (1 << i));
        remax(msk, q.K), remax(msk, q.V);
    }
    return dp[msk];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n) G(k)
        F(i, 1, n + 1) { cin >> a[i]; ind[a[i]].push_back(i); }
        fill_n(dp, 2 * n, pl{-1, -1});
        ll ans = LLONG_MIN;
        F(i, 0, 2 * n) if(r(i).K && r(i).V) ans = max(ans, r(i).K * r(i).V - k * i);
        cout << ans << '\n';
        F(i, 1, n + 1) ind[a[i]].clear();
    }
}
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
#define K 600
#define V second
#define M 1000000007 //998244353
#define N 40010

ll dp[N][K], lst[N];

bool palind(ll i) {
    string s = to_string(i), t = to_string(i);
    reverse(A(t));
    return s == t;
}

#define DP dp[n][k]
ll r(ll n, ll k) {
    if(n < 0) return 0;
    if(n == 0) return 1;
    if(~DP) return DP;
    if(!k) return 1;
    return DP = (r(n - lst[k], k) + r(n, k - 1)) % M;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dp, -1, sizeof dp);
    ll k = 0;
    F(i, 1, N) if(palind(i)) lst[k++] = i;
    G(tc) while(tc--) {
        G(n) cout << r(n, k - 1) << '\n';
    }
}
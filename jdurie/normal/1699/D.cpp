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

ll a[N], dp[N], ct[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n) fill_n(dp, n, 0);
        F(i, 0, n) {
            fill_n(ct, n + 1, 0);
            cin >> a[i]; ll mxc = 0;
            FD(j, i - 1, -1) {
                if(a[j] - a[i]) mxc = max(mxc, ++ct[a[j]]);
                if(a[i] == a[j] && (i - j) & 1 && dp[j] && mxc <= (i - j) / 2) dp[i] = max(dp[i], dp[j] + 1);
            }
            if(!(i & 1) && mxc <= i / 2) dp[i] = max(dp[i], 1ll);
        }
        fill_n(ct, n + 1, 0);
        ll ans = 0; ll mxc = 0;
        FD(j, n - 1, -1) {
            if((n - j) & 1 && mxc <= (n - j) / 2) ans = max(ans, dp[j]);
            mxc = max(mxc, ++ct[a[j]]);
        }
        cout << ans << '\n';
    }    
}
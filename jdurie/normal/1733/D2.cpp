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
#define N 5010

string s, t;
ll dp[N], n, x, y;

ll r(ll i) {
    if(i < 0) return 0;
    if(~dp[i]) return dp[i];
    if(s[i] == t[i]) return dp[i] = r(i - 1);
    dp[i] = r(i - 1) + y;
    FD(j, i - 1, -1) if(s[j] != t[j])
        return dp[i] = min(dp[i], 2 * x * (i - j) + r(j - 1));
    return dp[i];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        cin >> n >> x >> y >> s >> t;
        ll diff = 0, mnd = n, mxd = -1; 
        fill_n(dp, n, -1);
        F(i, 0, n) if(s[i] - t[i]) diff++, mnd = min(mnd, i), mxd = max(mxd, i);
        if(diff & 1) cout << "-1\n";
        else if(x >= y && diff == 2 && mnd + 1 == mxd) cout << min(2 * y, x) << '\n';
        else cout << r(n - 1) / 2 << '\n';
    }
}
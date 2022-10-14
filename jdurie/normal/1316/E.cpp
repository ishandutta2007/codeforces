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
#define F(i, l, r) for(ll i = l; i < r; i++)
#define FD(i, r, l) for(ll i = r; i > l; i--)
#define P(a, n) { cout << "{ "; F(_, 0, n) cout << a[_] << " "; cout << "}" << endl; }
#define EX(x) { cout << x << endl; exit(0); }
#define K first
#define V second
#define M 1000000000000000ll //998244353
#define N 100010

pl a[N];
ll s[N][7], dp[N][128], n, p, k;

#define PP dp[i][mask]

ll r(ll i, ll mask) {
    if(i < 0) return mask ? -M : 0;
    if(~PP) return PP;
    PP = 0;
    F(j, 0, p) if((mask >> j) & 1)
        PP = max(PP, s[a[i].V][j] + r(i - 1, mask ^ (1 << j)));
    ll prevP = p - __builtin_popcount(mask);
    if(n - i - 1 - prevP < k) PP = max(PP, a[i].K + r(i - 1, mask));
    else PP = max(PP, r(i - 1, mask));
    return PP;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dp, -1, sizeof dp);
    cin >> n >> p >> k;
    F(i, 0, n) cin >> a[i].K, a[i].V = i;
    sort(a, a + n);
    F(i, 0, n) F(j, 0, p) cin >> s[i][j];
    cout << r(n - 1, (1 << p) - 1) << '\n';
}
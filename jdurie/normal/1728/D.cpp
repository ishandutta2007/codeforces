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

ll n, dp[N][N];
string s;

ll verd(ll a, ll b) {
    if(s[a] == s[b]) return 2;
    if(s[a] < s[b]) return 1;
    return 3;
}

#define DP dp[l][r]
ll rr(ll l, ll r) {
    if(~DP) return DP;
    if(r == l + 1) return DP = s[r] == s[l] ? 2 : 1;
    ll vll = rr(l + 2, r) == 2 ? verd(l, l + 1) : rr(l + 2, r);
    ll vlr = rr(l + 1, r - 1) == 2 ? verd(l, r) : rr(l + 1, r - 1);
    ll vrl = rr(l + 1, r - 1) == 2 ? verd(r, l) : rr(l + 1, r - 1);
    ll vrr = rr(l, r - 2) == 2 ? verd(r, r - 1) : rr(l, r - 2);
    return DP = min(max(vll, vlr), max(vrl, vrr));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        cin >> s; n = s.size();
        F(i, 0, n) fill_n(dp[i], n, -1);
        char c = rr(0, n - 1);
        if(c == 1) cout << "Alice\n";
        else if(c == 3) cout << "Bob\n";
        else cout << "Draw\n";
    }
}
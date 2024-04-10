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
#define F(i, l, r) for(ll i = l; i < (r); i++)
#define FD(i, r, l) for(ll i = r; i > (l); i--)
#define P(a, n) { cout << "{ "; F(_, 0, n) cout << a[_] << " "; cout << "}\n"; }
#define EX(x) { cout << x << '\n'; exit(0); }
#define A(a) (a).begin(), (a).end()
#define K first
#define V second
#define M 1000000007 //998244353
#define N 2010

ll n, cur[N], dp[N][N];
ll dig[10] = {0b1110111, 0b0010010, 0b1011101, 0b1011011, 0b0111010, 0b1101011, 0b1101111, 0b1010010, 0b1111111, 0b1111011};

#define DP dp[i][k]
ll r(ll i, ll k) {
    if(~DP) return DP;
    if(i == n) return DP = (k ? LLONG_MIN : 0);
    for(ll j = 9; j >= 0; j--) {
        ll x = __builtin_popcount(cur[i] ^ dig[j]);
        if(x <= k && ((cur[i] & dig[j]) == cur[i]) && r(i + 1, k - x) != LLONG_MIN) return DP = j;
    }
    return DP = LLONG_MIN;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dp, -1, sizeof dp);
    cin >> n; G(k)
    F(i, 0, n) {
        GS(s) F(j, 0, 7) if(s[j] == '1') cur[i] |= 1 << (6 - j);
    }
    if(r(0, k) == LLONG_MIN) cout << "-1\n";
    else {
        F(i, 0, n) {
            cout << r(i, k);
            k -= __builtin_popcount(cur[i] ^ dig[r(i, k)]);
        }
        cout << '\n';
    }
}
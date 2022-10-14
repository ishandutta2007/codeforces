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
#define N 100010

ll t[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    t[0] = 1;
    F(i, 1, N) t[i] = t[i - 1] * 10 % M;
    F(i, 1, N) t[i] = (t[i] + t[i - 1]) % M;
    GS(s)
    ll n = s.size(), pref = 0, ans = 0;    
    F(i, 0, ((ll)s.size()) - 1) {
        pref = (pref * 10 + (s[i] - '0')) % M;
        ans = (ans + pref * t[n - i - 2] % M) % M;
    }
    ll suff = 0, pw = 1;
    FD(i, ((ll)s.size()) - 1, 0) {
        suff = (suff + pw * (s[i] - '0')) % M;
        pw = pw * 10 % M;
        ans = (ans + suff * i % M) % M;
    }
    cout << ans << '\n';
}
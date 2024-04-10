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

ll n, k, a[N], c[N];
set<pl> s;

ll f(ll sz, ll ct) {
    ll b = sz / ct, m = sz % ct;
    return m * (b + 1) * (b + 1) + (ct - m) * b * b;
}

pl diff(ll i) { return {f(a[i], c[i]) - f(a[i], c[i] + 1), i}; }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    fill_n(c, n, 1);
    F(i, 0, n) cin >> a[i], s.insert(diff(i));
    F(i, 0, k - n) {
        auto p = *s.rbegin(); s.erase(p);
        c[p.V]++; s.insert(diff(p.V));
    }
    ll ans = 0;
    F(i, 0, n) ans += f(a[i], c[i]);
    cout << ans << '\n';
}
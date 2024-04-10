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
#define M 998244353
#define N 200010

ll ans[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n)
    ans[n] = 10;
    if(n - 1) ans[n - 1] = 180;
    ll pp = 90;
    for(int i = n - 2; i >= 1; i--) {
        ans[i] = ((20 * pp % M) + (9 * pp * (n - i - 2 + 1) % M)) % M;
        pp = pp * 10 % M;
    }
    F(i, 1, n + 1) cout << ans[i] << ' ';
    cout << '\n';
}
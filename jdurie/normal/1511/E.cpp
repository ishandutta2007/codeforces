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
#define M 998244353
#define N 300010

string s[N];
ll v[N], p2[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    p2[0] = 1;
    F(i, 1, N) p2[i] = p2[i - 1] * 2 % M;
    v[0] = v[1] = 0;
    F(i, 2, N) v[i] = (p2[i - 2] + 2 * v[i - 2] + v[i - 1]) % M;
    G(n) G(m) ll w = 0;
    F(i, 0, n) cin >> s[i], w += count(A(s[i]), 'o');
    ll ans = 0;
    F(i, 0, n) {
        ll cur = 0;
        F(j, 0, m) if(s[i][j] == 'o') cur++; else {
            ans = (ans + p2[w - cur] * v[cur]) % M;
            cur = 0;
        }
        ans = (ans + p2[w - cur] * v[cur]) % M;
    }
    F(j, 0, m) {
        ll cur = 0;
        F(i, 0, n) if(s[i][j] == 'o') cur++; else {
            ans = (ans + p2[w - cur] * v[cur]) % M;
            cur = 0;
        }
        ans = (ans + p2[w - cur] * v[cur]) % M;
    }
    cout << ans << '\n';
}
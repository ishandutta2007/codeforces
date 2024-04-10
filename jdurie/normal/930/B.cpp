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

ll ct[26], x[26][26][N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    GS(s) ll n = s.size();
    for(char c : s) ct[c - 'a']++;
    F(i, 0, n) F(j, 1, n) x[s[i] - 'a'][s[(i + j) % n] - 'a'][j]++;
    ld ans = 0;
    F(c, 0, 26) {
        ll mx = 0;
        F(k, 1, n) {
            ll v = 0;
            F(d, 0, 26) if(x[c][d][k] == 1) v++;
            mx = max(mx, v);
        }
        ans += mx;
    }
    cout << fixed << setprecision(10) << ans / n << '\n';
}
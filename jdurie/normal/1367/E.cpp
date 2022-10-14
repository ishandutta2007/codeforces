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
#define M 1000000007 //998244353
#define N 100010

ll ct[26];

bool works(ll m, ll k) {
    ll h = 0;
    F(i, 0, 26) h += ct[i] / m;
    return h >= k;
}

ll bSearch(ll l, ll r, ll p) {
    if(l == r) return p * l;
    ll m = (l + r + 1) / 2;
    return works(m, p) ? bSearch(m, r, p) : bSearch(l, m - 1, p);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n) G(k) GS(s)
        fill(ct, ct + 26, 0);
        for(char c : s) ct[c - 'a']++;
        ll ans = 0;
        for(ll p = 1; p * p <= k; p++) if(!(k % p)) {
            ans = max(ans, bSearch(0, N, p));
            ans = max(ans, bSearch(0, N, k / p));
        }
        cout << ans << '\n';
    }
}
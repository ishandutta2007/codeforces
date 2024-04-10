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
//#define N 200010

ll bsch(ll l, ll r, ll n) {
    if(l == r) return l;
    ll m = (l + r) / 2;
    return 6 * m * m >= n ? bsch(l, m, n) : bsch(m + 1, r, n);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n)
        ll a = bsch(1, 100000, n);
        ll k = 0;
        while(6 * a * a - 4 * a * (k + 1) >= n) k++;
        ll ans = 3 * a - k;
        if(a > 1) {
            ll b = a - 1;
            ll x = 0;
            while(6 * b * b + 4 * b * x < n) x++;
            ans = min(ans, 3 * b + x);
        }
        cout << ans << '\n';
    }
}
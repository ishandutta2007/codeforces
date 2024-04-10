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
#define N 300010

ll a[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n1) G(n2) G(n3)
    F(i, 0, n1 + n2 + n3) cin >> a[i];
    ll s1 = accumulate(a, a + n1, 0ll);
    ll s2 = accumulate(a + n1, a + n1 + n2, 0ll);
    ll s3 = accumulate(a + n1 + n2, a + n1 + n2 + n3, 0ll);
    ll m1 = *min_element(a, a + n1);
    ll m2 = *min_element(a + n1, a + n1 + n2);
    ll m3 = *min_element(a + n1 + n2, a + n1 + n2 + n3);
    ll m = min({m1 + m2 + m3 - max({m1, m2, m3}), s1, s2, s3});
    cout << s1 + s2 + s3 - 2 * m << '\n';
}
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
//#define N 100010

ll pw[15], a[15];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    pw[0] = 1;
    F(i, 1, 15) pw[i] = 10 * pw[i - 1];
    G(tc) while(tc--) {
        G(n) G(k) k++;
        F(i, 0, n) cin >> a[i];
        ll sm = 0;
        F(i, 0, n - 1) {
            ll z = min(k, pw[a[i + 1] - a[i]] - 1);
            k -= z, sm += pw[a[i]] * z;
        }
        sm += pw[a[n - 1]] * k;
        cout << sm << '\n';
    }
}
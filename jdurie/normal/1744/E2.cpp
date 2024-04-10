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

vector<ll> factors(ll q) {
    vector<ll> f;
    for(ll x = 1; x * x <= q; ++x) if(!(q % x)) {
        f.push_back(x);
        f.push_back(q / x);
    }
    return f;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(a) G(b) G(c) G(d)
        vector<ll> fa = factors(a), fb = factors(b);
        ll ax = -1, ay = -1;
        for(ll f1 : fa) for(ll f2 : fb) {
            ll m = f1 * f2, n = a * b / m;
            ll x = a + 1 + (m - (a + 1) % m) % m, y = b + 1 + (n - (b + 1) % n) % n;
            if(x <= c && y <= d) ax = x, ay = y;
        }
        cout << ax << ' ' << ay << '\n';
    }
}
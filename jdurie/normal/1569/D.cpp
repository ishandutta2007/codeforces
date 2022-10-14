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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        map<ll, map<ll, ll>> xct, yct;
        set<ll> x, y;
        G(n) G(m) G(k)
        while(n--) { G(z) x.insert(z); }
        while(m--) { G(z) y.insert(z); }
        while(k--) {
            G(a) G(b)
            if(x.count(a) && y.count(b)) continue;
            else if(x.count(a)) yct[*y.upper_bound(b)][a]++;
            else xct[*x.upper_bound(a)][b]++;
        }
        ll ans = 0;
        for(auto a : yct) {
            ll tot = 0;
            for(auto b : a.V) { ans += b.V * tot; tot += b.V; }
        }
        for(auto a : xct) {
            ll tot = 0;
            for(auto b : a.V) { ans += b.V * tot; tot += b.V; }
        }
        cout << ans << '\n';
    }
}
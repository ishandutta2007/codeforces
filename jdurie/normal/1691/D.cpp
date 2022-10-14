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
#define N 200010

namespace sgtree {
    typedef pair<pl, ll> T;
    T id = {{LLONG_MIN, LLONG_MAX}, LLONG_MIN}, t[2 * N];

    T f(T a, T b) { return {{max(a.K.K, b.K.K), min(a.K.V, b.K.V)}, max(a.V, b.V)}; }

    void modify(ll p, T v) { //set value v at position p
        for(t[p += N] = v; p /= 2;) t[p] = f(t[2 * p], t[2 * p + 1]);
    }

    T query(ll l, ll r) { //query on interval [l, r)
        T resl = id, resr = id;
        for(l += N, r += N; l < r; l /= 2, r /= 2) {
            if(l & 1) resl = f(resl, t[l++]);
            if(r & 1) resr = f(t[--r], resr);
        }
        return f(resl, resr);
    }
}

ll a[N];

ll bschl(ll l, ll r, ll i) {
    if(l == r) return l;
    ll m = (l + r) / 2;
    return sgtree::query(m, i + 1).V > a[i] ? bschl(m + 1, r, i) : bschl(l, m, i);
}

ll bschr(ll l, ll r, ll i) {
    if(l == r) return l;
    ll m = (l + r + 1) / 2;
    return sgtree::query(i, m + 1).V > a[i] ? bschr(l, m - 1, i) : bschr(m, r, i);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n) F(i, 1, n + 1) cin >> a[i];
        ll ps = 0;
        sgtree::modify(0, {{0, 0}, 0});
        F(i, 1, n + 1) ps += a[i], sgtree::modify(i, {{ps, ps}, a[i]});
        string ans = "YES\n";
        F(i, 1, n + 1) if(a[i] > 0) {
            ll l = bschl(1, i, i), r = bschr(i, n, i);
            ll mxv = sgtree::query(i, r + 1).K.K - sgtree::query(l - 1, i).K.V;
            if(mxv > a[i]) ans = "NO\n";
        }
        cout << ans;
    }    
}
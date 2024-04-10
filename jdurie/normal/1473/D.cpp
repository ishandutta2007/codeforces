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
    typedef pl T;
    T id = {LLONG_MAX, LLONG_MIN}, t[2 * N];

    T f(T a, T b) { return {min(a.K, b.K), max(a.V, b.V)}; }

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

ll psum[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n) G(q)
        GS(s)
        ll cur = 0;
        F(i, 0, n) {
            if(s[i] == '+') cur++; else cur--;
            psum[i] = cur;
            sgtree::modify(i, {cur, cur});
        }
        while(q--) {
            G(l) G(r)
            pl pr = sgtree::query(r, n);
            if(r - n) {
                ll k = psum[r - 1] - (l - 1 ? psum[l - 2] : 0);
                pr.K -= k; pr.V -= k;
            }
            pl p = sgtree::f(sgtree::query(0, l - 1), pr);
            if(p.K > 0) p.K = 0;
            if(p.V < 0) p.V = 0;
            if(p.K >= 10 * n) cout << "1\n";
            else cout << p.V - p.K + 1 << '\n';
        }
    }
}
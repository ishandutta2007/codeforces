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
    T id = {1, 1}, t[2 * N];

    T f(T a, T b) { return {min(a.K, b.K), min(a.V, b.V)}; }

    void modify(ll p, T v) { //set value v at position p
        p += N; t[p] = {t[p].K + v.K, t[p].V + v.V};
        for(; p /= 2;) t[p] = f(t[2 * p], t[2 * p + 1]);
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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) G(q) while(q--) {
        G(t) G(x) G(y)
        if(t == 1) sgtree::modify(x, {1, 0}), sgtree::modify(y, {0, 1});
        else if(t == 2) sgtree::modify(x, {-1, 0}), sgtree::modify(y, {0, -1});
        else {
            G(x2) G(y2) x2++; y2++;
            if(sgtree::query(x, x2).K || sgtree::query(y, y2).V) cout << "Yes\n";
            else cout << "No\n";
        }
    }
}
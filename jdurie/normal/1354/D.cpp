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
#define N 1000010

namespace segtree {
    ll t[2 * N];
    ll n;  // array size

    void modify(int l, int r, int value) {
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l&1) t[l++] += value;
            if (r&1) t[--r] += value;
        }
    }

    int query(int p) {
        int res = 0;
        for (p += n; p > 0; p >>= 1) res += t[p];
        return res;
    }
}

ll bSearch(ll l, ll r, ll ct) {
    if(l == r) return l;
    ll m = (l + r) / 2;
    return segtree::query(m) < ct ? bSearch(m + 1, r, ct) : bSearch(l, m, ct);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    G(n) G(q)
    segtree::n = n;
    F(i, 0, n + q) {
        G(x)
        if(x > 0) segtree::modify(x - 1, n, 1);
        else {
            ll p = bSearch(0, n - 1, -x);
            segtree::modify(p, n, -1);           
        }
    }
    F(i, 0, n) if(segtree::query(i)) EX(i + 1)
    cout << "0\n";
}
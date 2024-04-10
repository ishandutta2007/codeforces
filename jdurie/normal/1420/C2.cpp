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
#define F(i, l, r) for(ll i = l; i < (r); i++)
#define FD(i, r, l) for(ll i = r; i > (l); i--)
#define P(a, n) { cout << "{ "; F(_, 0, n) cout << a[_] << " "; cout << "}\n"; }
#define EX(x) { cout << x << '\n'; exit(0); }
#define A(a) (a).begin(), (a).end()
#define K first
#define V second
#define M 1000000007 //998244353
#define N 300010

ll n, q, a[N], suff[N], pref[N];

struct segtree {
    typedef pl T;
    T id = {0, 0}, t[2 * N];
    ll n;  // array size (use N for single tc)
    T f(T c, T b) { return {c.K + b.K, c.V + b.V}; }

    void modify(ll p, T value) {  // set value at position p
        for (t[p += n] = value; p /= 2;) t[p] = f(t[2 * p], t[2 * p + 1]);
    }

    T query(ll l, ll r) { // query on interval [l, r)
        T resl = id, resr = id;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l & 1) resl = f(resl, t[l++]);
            if (r & 1) resr = f(t[--r], resr);
        }
        return f(resl, resr);
    }
};

segtree stree;

void doModify(ll i) {
    if(i < 0 || i >= n) return;
    pl p = {0, 0};
    if(i) p.K = max(0ll, a[i - 1] - a[i]);
    if(i - n + 1) p.V = max(0ll, a[i + 1] - a[i]);
    stree.modify(i, p); 
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        cin >> n >> q;
        F(i, 0, n) cin >> a[i];
        stree.n = n;
        ll posm = -1;
        F(i, 0, n) {
            doModify(i);
            if(a[i] == n) posm = i;
        }
        cout << n + stree.query(0, posm).K + stree.query(posm + 1, n).V << '\n';
        while(q--) {
            G(l) G(r) l--, r--;
            swap(a[l], a[r]);
            doModify(l), doModify(l - 1), doModify(l + 1);
            doModify(r), doModify(r - 1), doModify(r + 1);
            if(posm == l) posm = r;
            else if(posm == r) posm = l;
            cout << n + stree.query(0, posm).K + stree.query(posm + 1, n).V << '\n';
        }
    }
}
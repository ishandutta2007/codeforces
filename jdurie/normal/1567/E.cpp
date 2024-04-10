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

ll a[N];

set<ll> st;

ll tri(ll x) { return x * (x + 1) / 2; }

namespace sgtree {
    typedef ll T;
    T id = 0, t[2 * N];

    T f(T a, T b) { return a + b; }

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

void domodify(ll x) {
    sgtree::modify(x, tri(*st.upper_bound(x) - x));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) G(q)
    F(i, 0, n) cin >> a[i];
    F(i, 1, n) if(a[i] < a[i - 1]) st.insert(i);
    st.insert(0); st.insert(n);
    for(ll x : st) if(x < n) domodify(x);
    while(q--) {
        G(t)
        if(t == 1) {
            G(i) G(y) i--;
            st.erase(i);
            sgtree::modify(i, 0);
            st.erase(i + 1);
            sgtree::modify(i + 1, 0);
            a[i] = y;
            if(i == 0 || a[i] < a[i - 1]) st.insert(i);
            if(i != n - 1 && a[i + 1] < a[i]) st.insert(i + 1);
            if(st.count(i)) domodify(i);
            if(st.count(i + 1)) domodify(i + 1);
            if(i > *st.begin()) domodify(*--st.lower_bound(i));
        } else {
            G(l) G(r) l--; r--;
            ll nl = *st.upper_bound(l), nr = *--st.upper_bound(r);
            if(nl > r) cout << tri(r - l + 1) << '\n';
            else cout << tri(nl - l) + tri(r - nr + 1) + sgtree::query(nl, nr) << '\n';
        }
    }
}
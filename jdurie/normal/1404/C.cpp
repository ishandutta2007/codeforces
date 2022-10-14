#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
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
 
typedef tree<ll, null_type, less_equal<ll>,
rb_tree_tag, tree_order_statistics_node_update> set_t;

struct segtree {
    typedef vector<ll> T;
    T t[2 * N];

    ll f(ll i, ll k) { return (ll)(t[i].size() - (lower_bound(A(t[i]), k) - t[i].begin())); }

    void build() {
        FD(i, N - 1, 0) merge(A(t[2 * i]), A(t[2 * i + 1]), back_inserter(t[i]));
    }

    ll query(ll l, ll r, ll k) { // query on interval [l, r)
        ll res = 0;
        for (l += N, r += N; l < r; l /= 2, r /= 2) {
            if (l & 1) res += f(l++, k);
            if (r & 1) res += f(--r, k);
        }
        return res;
    }
};

set_t oset;
segtree stree;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) G(q)
    F(i, 1, n + 1) {
        G(x) ll y = 0;
        if(x > i || i - x > i - 1) y = 0;
        else if(x == i) y = i;
        else y = *oset.find_by_order(x - 1);
        stree.t[i + N] = {y};
        oset.insert(y);
    }
    stree.build();
    while(q--) {
        G(l) G(r)
        cout << stree.query(l + 1, n - r + 1, l + 1) << '\n';
    }
}
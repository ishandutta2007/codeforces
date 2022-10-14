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
#define EX(x) { cout << x << '\n'; exit(0); }
#define A(a) (a).begin(), (a).end()
#define K first
#define V second
#define M 1000000007 //998244353
#define P(l) (1ll << l)
#define MOD(k, l) ((k % P(l) + P(l)) % P(l))
#define L(x) (63 - __builtin_clzll(x))
//#define N 100010

ll relab[100], shft[100];

void pr(ll x) {
    ll v = x + relab[L(x)];
    if(L(v) != L(x)) v -= P(L(x));
    cout << v << ' ';
    if(x == 1) { cout << '\n'; return; }
    v = x + shft[L(x)];
    if(L(v) != L(x)) v -= P(L(x));
    pr(v >> 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(q) while(q--) {
        G(t) G(x)
        ll l = L(x);
        if(t == 1) { G(k) relab[l] = MOD(relab[l] - k, l); }
        else if(t == 2) { G(k) shft[l] = MOD(shft[l] + k, l); }
        else {
            ll v = x - relab[L(x)];
            if(L(v) != L(x)) v += P(L(x));
            pr(v);
        }
    }
}
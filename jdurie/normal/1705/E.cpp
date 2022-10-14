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
set<pl> rgs;

void insert(ll x) {
    if(rgs.empty() || x > rgs.rbegin()->K) {
        rgs.insert({x, x});
        return;
    }
    pl p = *rgs.lower_bound({x, 0});
    if(x >= p.V) {
        rgs.erase(p);
        if(x > p.V) rgs.insert({x - 1, p.V});
        insert(p.K + 1);
    } else rgs.insert({x, x});
}

void remove(ll x) {
    pl p = *rgs.lower_bound({x, 0});
    rgs.erase(p);
    if(x >= p.V) {
        if(x > p.V) rgs.insert({x - 1, p.V});
        if(x < p.K) rgs.insert({p.K, x + 1});
    } else {
        if(p.K - p.V) rgs.insert({p.K, p.V + 1});
        rgs.insert({p.V - 1, x});
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) G(q)
    F(i, 0, n) cin >> a[i], insert(a[i]);
    while(q--) {
        G(k) G(x) k--;
        remove(a[k]);
        a[k] = x;
        insert(a[k]);
        cout << rgs.rbegin()->K << '\n';
    }
}
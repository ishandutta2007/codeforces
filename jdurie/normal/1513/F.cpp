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

multiset<ll> ab, ba;
set<ll> vals;
map<ll, multiset<ll>> ma, mb; 
ll a[N], b[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) ll ans = 0;
    F(i, 0, n) cin >> a[i], vals.insert(a[i]);
    F(i, 0, n) cin >> b[i], vals.insert(b[i]);
    F(i, 0, n) {
        if(a[i] > b[i]) mb[b[i]].insert(a[i]);
        else ma[a[i]].insert(b[i]);
        ans += abs(a[i] - b[i]);
    }
    ll mx = 0;
    for(ll v : vals) {
        for(ll aa : ma[v]) ba.insert(aa);
        for(ll bb : mb[v]) ab.insert(bb);
        ba.erase(v); ab.erase(v);
        if(ba.size() && ab.size()) mx = max(mx, min(*ba.rbegin(), *ab.rbegin()) - v);
    }
    cout << ans - 2 * mx << '\n';
}
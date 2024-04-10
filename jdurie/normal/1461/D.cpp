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
#define N 1000010

ll ct[N];
set<ll> s;

void procecc(ll l, ll r) {
    if(l > r) return;
    while(!ct[l]) { l++; if(l > r) return; }
    while(!ct[r]) r--;
    ll sm = 0;
    F(i, l, r + 1) sm += ct[i] * i;
    s.insert(sm);
    if(l - r) {
        procecc(l, (l + r) / 2);
        procecc((l + r) / 2 + 1, r);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        fill_n(ct, N, 0);
        s.clear();
        G(n) G(q) F(i, 0, n) { G(x) ct[x]++; }
        procecc(0, 1000000);
        while(q--) { G(x) cout << (s.count(x) ? "Yes\n" : "No\n"); }
    }    
}
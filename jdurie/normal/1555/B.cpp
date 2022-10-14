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
//#define N 100010

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(W) G(H)
        G(x1) G(y1) G(x2) G(y2)
        G(w) G(h)
        if(w + (x2 - x1) > W && h + (y2 - y1) > H) cout << "-1\n";
        else {
            ll wcb = max(0ll, w - x1), wca = max(0ll, x2 - (W - w));
            ll hcb = max(0ll, h - y1), hca = max(0ll, y2 - (H - h));
            ll wd = min(wcb, wca), hd = min(hcb, hca);
            if(w + (x2 - x1) > W) wd = LLONG_MAX;
            if(h + (y2 - y1) > H) hd = LLONG_MAX;
            cout << min(wd, hd) << '\n';
        }
    }
}
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
        G(n) G(l) G(r)
        map<ll, ll> lf, rt;
        F(i, 0, l) { G(x) lf[x]++; }
        F(i, 0, r) { G(x) rt[x]++; }
        ll ps = 0, cst = 0;
        for(auto &p : lf) if(rt.count(p.K)) {
            ll c = min(p.V, rt[p.K]);
            ps += c;
            p.V -= c, rt[p.K] -= c;
            l -= c; r -= c;
        }
        for(auto &p : lf)
            while(p.V >= 2 && l > r) {
                p.V -= 2;
                l -= 2;
                ps++, cst++;
            }
        for(auto &p : rt)
            while(p.V >= 2 && r > l) {
                p.V -= 2;
                r -= 2;
                ps++, cst++;
            }
        cout << cst + abs(r - l) / 2 + (r + l) / 2 << '\n';
    }
}
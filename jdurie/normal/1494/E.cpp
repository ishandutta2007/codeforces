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
#define GC(s) char s; cin >> s;
#define F(i, l, r) for(ll i = l; i < (r); ++i)
#define FD(i, r, l) for(ll i = r; i > (l); --i)
#define P(a, n) { cout << "{ "; F(_, 0, n) cout << a[_] << " "; cout << "}\n"; }
#define EX(x) { cout << x << '\n'; exit(0); }
#define A(a) (a).begin(), (a).end()
#define K first
#define V second
#define M 1000000007 //998244353
//#define N 100010

map<pl, char> m;
ll a = 0, ca = 0;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) G(q)
    while(q--) {
        GC(t)
        if(t == '+') {
            G(u) G(v) GC(c)
            if(m.count({v, u})) {
                a++;
                if(m[{v, u}] == c) ca++;
            }
            m[{u, v}] = c;
        } else if(t == '-') {
            G(u) G(v)
            if(m.count({v, u})) {
                a--;
                if(m[{v, u}] == m[{u, v}]) ca--;
            }
            m.erase({u, v});
        } else {
            G(k)
            if(k & 1) cout << (a ? "YES\n" : "NO\n");
            else cout << (ca ? "YES\n" : "NO\n");
        }
    }
}
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
#define N 100010
#define Z 100000

pl p[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) G(m) p[0] = {0, 0};
    F(i, 1, m + 1) p[i] = {-1, -1};
    F(zz, 1, n + 1) {
        G(t) G(x) G(y)
        if(t == 1) {
            x = (x + Z - 1) / Z;
            F(i, 0, m + 1) if(~p[i].K && (p[i].K - zz || p[i].V)) {
                ll nxtv = p[i].K == zz ? p[i].V - 1 : y - 1;
                if(i + x <= m && !~p[i + x].K) p[i + x] = {zz, nxtv};
            }
        } else {
            F(i, 0, m + 1) if(~p[i].K && (p[i].K - zz || p[i].V)) {
                ll nxtv = p[i].K == zz ? p[i].V - 1 : y - 1;
                ll nxtx = (i * x + Z - 1) / Z;
                if(nxtx <= m && !~p[nxtx].K) p[nxtx] = {zz, nxtv};
            }
        }
    }
    F(i, 1, m + 1) cout << p[i].K << ' ';
    cout << '\n';
}
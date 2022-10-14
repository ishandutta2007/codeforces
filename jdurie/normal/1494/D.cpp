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
#define N 2010

ll par[N], apar[N], a[N][N], s[N];
set<pair<ll, pl>> st;
ll dsu(ll i) { return par[i] == i ? i : par[i] = dsu(par[i]); }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    iota(par, par + N, 0);
    G(n)
    F(i, 1, n + 1) {
        F(j, 1, n + 1) cin >> a[i][j], st.insert({a[i][j], {i, j}});
        s[i] = a[i][i];
    }
    ll cr = n + 1;
    for(auto au : st) {
        ll v = au.K, i = au.V.K, j = au.V.V;
        ll ip = dsu(i), jp = dsu(j);
        if(s[ip] >= v) continue;
        par[ip] = apar[ip] = cr;
        F(k, 1, n + 1) if(a[i][k] == v) {
            ll kp = dsu(k);
            par[kp] = apar[kp] = cr;
        }
        s[cr] = v;
        cr++;
    }
    cout << cr - 1 << '\n';
    F(i, 1, cr) cout << s[i] << ' ';
    cout << '\n' << cr - 1 << '\n';
    F(i, 1, cr - 1) if(apar[i]) cout << i << ' ' << apar[i] << '\n';
}
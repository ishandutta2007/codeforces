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
#define M 998244353
#define N 500010

pl port[N];
ll act[N], vals[N], x[N];
ll loop[N];
pl ap[N];
map<ll, ll> id;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n)
    F(i, 0, n) cin >> port[i].K >> port[i].V >> act[i], vals[2 * i] = port[i].K, vals[2 * i + 1] = port[i].V;
    sort(vals, vals + 2 * n);
    F(i, 0, 2 * n) id[vals[i]] = i;
    F(i, 0, n) ap[i].K = id[port[i].K], ap[i].V = id[port[i].V];
    ll ij = 1;
    F(i, 0, n) {
        while(ij <= ap[i].K) { x[ij] = x[ij - 1]; ij++; }
        loop[i] = (port[i].K - port[i].V + x[ap[i].K] - x[ap[i].V] + 2 * M) % M;
        x[ap[i].K] = (x[ap[i].K] + loop[i]) % M;
    }
    ll ans = port[n - 1].K + 1;
    F(i, 0, n) if(act[i]) ans += loop[i];
    cout << ans % M << '\n';
}
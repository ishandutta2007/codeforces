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
#define L 30

ll ans[N], nt[N];
vector<pl> va[N];
ll mk = (1ll << L) - 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) G(q)
    vector<pair<pl, ll>> vq;
    while(q--) {
        G(i) G(j) i--; j--; if(i > j) swap(i, j);
        G(x) vq.push_back({{i, j}, x}); va[i].push_back({j, x});
        nt[i] |= (x ^ mk); nt[j] |= (x ^ mk);
        if(i == j) ans[i] = x;
    }
    F(j, 0, L) {
        for(auto a : vq) if((a.V >> j) & 1) {
            if((nt[a.K.K] >> j) & 1) ans[a.K.V] |= (1 << j);
            else if((nt[a.K.V] >> j) & 1) ans[a.K.K] |= (1 << j);
        }
        F(i, 0, n) if(!((ans[i] >> j) & 1)) for(pl p : va[i]) if((p.V >> j) & 1) ans[p.K] |= (1 << j);
    }
    F(i, 0, n) cout << ans[i] << ' ';
    cout << '\n';
}
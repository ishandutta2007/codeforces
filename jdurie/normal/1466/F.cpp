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
#define N 500010

ll par[N], hasL[N];
ll dsu(ll i) { return par[i] == i ? i : par[i] = dsu(par[i]); }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(m) G(n)
    iota(par, par + N, 0);
    vector<ll> v;
    F(i, 1, m + 1) {
        G(k)
        if(k == 1) {
            G(x) x = dsu(x);
            if(!hasL[x]) {
                v.push_back(i);
                hasL[x] = true;
            }
        } else {
            G(u) G(w)
            u = dsu(u), w = dsu(w);
            if(u - w && (!hasL[u] || !hasL[w])) {
                hasL[u] |= hasL[w];
                par[w] = u;
                v.push_back(i);
            }
        }
    }
    ll p2 = 1;
    F(i, 0, v.size()) p2 = 2 * p2 % M;
    cout << p2 << ' ' << v.size() << '\n';
    for(ll x : v) cout << x << ' ';
    cout << '\n';
}
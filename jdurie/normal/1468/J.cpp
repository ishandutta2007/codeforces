//Codeforces Template
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

pair<ll, pl> edges[N];
ll par[N];

ll dsu(ll i) { return par[i] == i ? i : par[i] = dsu(par[i]); }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n) G(m) G(k)
        ll mnd = LLONG_MAX;
        F(i, 0, m) {
            cin >> edges[i].V.K >> edges[i].V.V >> edges[i].K;
            mnd = min(mnd, abs(edges[i].K - k));
        }
        sort(edges, edges + m);
        iota(par, par + n + 1, 0);
        bool used = false;
        ll cst = 0;
        F(i, 0, m) {
            ll u = dsu(edges[i].V.K), v = dsu(edges[i].V.V);
            if(u - v) {
                if(edges[i].K >= k) used = true, cst += edges[i].K - k;
                par[u] = v;
            }
        }
        cout << (used ? cst : cst + mnd) << '\n';
    }    
}
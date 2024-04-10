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

vector<pair<pl, ll>> edges;
ll n, m, par[N];

ll dsu(ll i) { return par[i] == i ? i : par[i] = dsu(par[i]); }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        cin >> n >> m;
        while(m--) {
            G(u) G(v) G(w)
            edges.emplace_back(pl{u, v}, w);
        }
        ll ans = 0;
        FD(k, 30, -1) {
            iota(par, par + n + 1, 0);
            for(auto a : edges) if(a.V < (1 << k) && ~a.V) par[dsu(a.K.V)] = dsu(a.K.K);
            bool c = true;
            F(i, 2, n + 1) if(dsu(i) - dsu(1)) c = false;
            if(!c) ans |= 1 << k;
            for(auto& a : edges) if(!c) a.V %= (1 << k); else if((a.V >> k) & 1) a.V = -1;
        }
        cout << ans << '\n';
        edges.clear();
    }
}
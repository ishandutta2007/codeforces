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

ll par[N], side[N], sz[N], ct[3];
bool ok;
vector<ll> graph[N];
vector<pl> sus;

ll dsu(ll i) { return par[i] == i ? i : par[i] = dsu(par[i]); }

void dfs(ll i, ll c) {
    ct[c] += sz[i];
    side[i] = c;
    for(ll j : graph[i])
        if(side[j] == side[i]) ok = false;
        else if(!side[j]) dfs(j, 3 - c);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n) G(m)
        iota(par, par + n + 1, 0);
        fill_n(sz, n + 1, 1);
        ok = true;
        while(m--) {
            G(u) G(v) GS(s)
            if(s[0] == 'c') {
                if(dsu(u) - dsu(v)) {
                    sz[dsu(v)] += sz[dsu(u)];
                    par[dsu(u)] = dsu(v);
                }
            } else sus.emplace_back(u, v);
        }
        for(pl p : sus) graph[dsu(p.K)].push_back(dsu(p.V)), graph[dsu(p.V)].push_back(dsu(p.K));
        ll ans = 0;
        F(i, 1, n + 1) if(dsu(i) == i && !side[i]) {
            ct[1] = ct[2] = 0;
            dfs(i, 1);
            ans += max(ct[1], ct[2]);
        }
        cout << (ok ? ans : -1) << '\n';
        F(i, 1, n + 1) graph[i].clear();
        fill_n(side, n + 1, 0);
        sus.clear();
    }
}
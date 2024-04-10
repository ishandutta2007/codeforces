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
#define N 1010

bool wait[N][N];
ll a[N], indeg[N], dp[N];
vector<ll> graph[N], pars[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n) G(m)
        F(i, 1, n + 1) cin >> a[i], indeg[i] = 0;
        while(m--) {
            G(u) G(v)
            graph[u].push_back(v);
            pars[v].push_back(u);
            indeg[v]++;
        }
        vector<ll> topo;
        F(i, 1, n + 1) if(!indeg[i]) topo.push_back(i);
        F(i, 0, topo.size()) for(ll j : graph[topo[i]]) if(!--indeg[j]) topo.push_back(j);
        bool overf = false;
        for(ll i : topo) {
            ll rsv = a[i];
            dp[i] = a[i];
            for(ll j : pars[i]) {
                if(dp[i] + dp[j] > M) overf = true;
                dp[i] = (dp[i] + dp[j]) % M;
            }
            F(t, 0, N) {
                for(ll j : pars[i]) if(t && !wait[j][t - 1]) rsv++;
                if(rsv) wait[i][t] = false, rsv--; else wait[i][t] = true;
            }
        }
        ll h = topo.back();
        if(!overf && count(wait[h], wait[h] + N, 0) == dp[h]) {
            ll x = N - 1;
            while(x >= 0 && wait[h][x]) x--;
            cout << x + 1 << '\n';
        } else cout << (dp[h] + count(wait[h], wait[h] + N, 1)) % M << '\n';
        F(i, 1, n + 1) graph[i].clear(), pars[i].clear();
    }
}
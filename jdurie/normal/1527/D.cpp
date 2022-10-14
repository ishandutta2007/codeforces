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
#define L 20

ll dep[N], par[N][L], path[N], ans[N], sz[N];
vector<ll> tree[N];

ll dfs(ll i, ll p) {
    dep[i] = dep[p] + 1;
    par[i][0] = p;
    sz[i] = 1;
    F(l, 1, L) par[i][l] = par[par[i][l - 1]][l - 1];
    for(ll j : tree[i]) if(j - p) sz[i] += dfs(j, i);
    return sz[i];
}

ll lca(ll a, ll b) {
    if(dep[a] < dep[b]) swap(a, b);
    FD(l, L - 1, -1) if((dep[a] - dep[b]) >> l) a = par[a][l];
    if(a == b) return a;
    FD(l, L - 1, -1) if(par[a][l] - par[b][l]) a = par[a][l], b = par[b][l];
    return par[a][0];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n)
        F(i, 0, n - 1) {
            G(u) G(v)
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        dfs(0, 0);
        path[0] = n * (n - 1) / 2;
        for(ll v : tree[0]) path[0] -= sz[v] * (sz[v] - 1) / 2;
        ll sec = 1; while(dep[sec] > 2) sec = par[sec][0];
        ll top = n - sz[sec], v = 1, v2 = 0;
        F(i, 1, n) {
            ll l = lca(v, i), l2 = lca(v2, i);
            if(l == v) v = i;
            else if(l - i && l2 == v2) {
                if(l) break;
                v2 = i;
            } else if(l - i && l2 - i) break;
            path[i] = (v2 ? sz[v2] : top) * sz[v];
        }   
        path[n] = 0;
        ans[0] = n * (n - 1) / 2 - path[0];
        F(i, 1, n + 1) ans[i] = path[i - 1] - path[i];
        F(i, 0, n + 1) cout << ans[i] << ' ';
        cout << '\n';
        F(i, 0, n) tree[i].clear(), dep[i] = path[i] = 0;
    }
}
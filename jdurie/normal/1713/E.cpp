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
#define N 1010

ll a[N][N], par[N];
bool used[N], fl[N];
vector<pl> graph[N];

ll dsu(ll i) { return par[i] == i ? i : par[i] = dsu(par[i]); }

void dfs(ll i, ll f) {
    fl[i] = f;
    used[i] = true;
    for(pl p : graph[i]) if(!used[p.K]) dfs(p.K, f ^ p.V);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n)
        F(i, 0, n) F(j, 0, n) cin >> a[i][j];
        iota(par, par + n, 0ll);
        F(i, 0, n) F(j, i + 1, n) if(dsu(i) - dsu(j) && a[i][j] - a[j][i]) {
            graph[i].emplace_back(j, a[i][j] > a[j][i]);
            graph[j].emplace_back(i, a[i][j] > a[j][i]);
            par[dsu(i)] = dsu(j);
        }
        fill_n(used, n, 0);
        F(i, 0, n) if(!used[i]) dfs(i, 0);
        F(i, 0, n) if(fl[i]) F(j, 0, n) swap(a[i][j], a[j][i]);
        F(i, 0, n) F(j, 0, n) cout << a[i][j] << " \n"[j == n - 1];
        F(i, 0, n) graph[i].clear();
    }
}
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

vector<ll> graph[N];
bool cyc[N], used[N];
ll dep[N], par[N];

void dfs(ll i, ll p) {
    par[i] = p;
    dep[i] = dep[p] + 1;
    for(ll j : graph[i]) if(j - p) {
        if(!dep[j]) dfs(j, i);
        else if(dep[j] < dep[i])
            for(ll k = i, c = 0; c <= dep[i] - dep[j]; k = par[k], ++c)
                cyc[k] = true;
    }
}

ll dfs2(ll i) {
    ll sz = 1;
    used[i] = true;
    for(ll j : graph[i]) if((!cyc[i] || !cyc[j]) && !used[j]) sz += dfs2(j);
    return sz;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n)
        fill_n(cyc, n + 1, false);
        F(i, 1, n + 1) graph[i].clear();
        fill_n(dep, n + 1, 0);
        fill_n(used, n + 1, false);
        F(i, 0, n) {
            G(u) G(v)
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        dfs(1, 1);
        vector<ll> compSizes;
        F(i, 1, n + 1) if(!used[i]) compSizes.push_back(dfs2(i));
        ll ans = 0;
        for(ll s : compSizes) 
            ans += s * (s - 1) + s * 2 * (n - s);
        cout << ans / 2 << '\n'; 
    }
}
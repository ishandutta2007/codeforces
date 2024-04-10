#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
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
#define F(i, l, r) for(ll i = l; i < r; i++)
#define FD(i, r, l) for(ll i = r; i > l; i--)
#define P(a, n) { cout << "{ "; F(_, 0, n) cout << a[_] << " "; cout << "}\n"; }
#define EX(x) { cout << x << '\n'; goto eotc; }
#define A(x) (x).begin(), (x).end()
#define K first
#define V second
#define M 1000000007 //998244353
#define N 500010

vector<ll> graph[N];
vector<pl> pairs;
ll par[N], dep[N], n, m;
bool path;

void doPath(ll v) {
    cout << "PATH\n" << (n + 1) / 2 << '\n';
    F(i, 0, (n + 1) / 2) cout << v << ' ', v = par[v];
    cout << '\n';
    path = true;
}

void dfs(ll i, ll p, ll d) {
    par[i] = p;
    if(!dep[d]) dep[d] = i;
    else pairs.emplace_back(i, dep[d]), dep[d] = 0;
    if(d >= (n + 1) / 2 && !path) doPath(i);
    for(ll j : graph[i]) if(!par[j]) dfs(j, i, d + 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        cin >> n >> m;
        path = false;
        pairs.clear();
        fill_n(dep, n + 1, 0);
        fill_n(par, n + 1, 0);
        F(i, 1, n + 1) graph[i].clear();
        while(m--) {
            G(u) G(v)
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        dfs(1, -1, 1);
        if(!path) {
            cout << "PAIRING\n" << pairs.size() << '\n';
            for(pl p : pairs) cout << p.K << ' ' << p.V << '\n';
        }
    }
}
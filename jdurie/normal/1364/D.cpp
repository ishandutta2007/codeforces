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
#define P(a, n) { cout << "{ "; F(_, 0, n) cout << a[_] << " "; cout << "}" << endl; }
#define EX(x) { cout << x << endl; exit(0); }
#define K first
#define V second
#define M 1000000007 //998244353
#define N 100010

vector<ll> graph[N], iset[2], backOut[N];
ll dep[N], par[N], k; //make depth of root 1

void dfs(ll i, ll p, ll d) {
    dep[i] = d;
    par[i] = p;
    for(ll j : graph[i]) if(j != p) {
        if(dep[j] && dep[j] < dep[i])
            backOut[i].push_back(j);
        else if(!dep[j]) dfs(j, i, d + 1);
    }
}

void dfsInd(ll i, ll p, ll b) {
    iset[b].push_back(i);
    if(iset[b].size() == (k + 1) / 2) {
        cout << "1\n";
        for(ll v : iset[b]) cout << v << ' '; EX('\n')
    }
    for(ll j : graph[i]) if(j != p) dfsInd(j, i, b ^ 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) G(m)
    cin >> k;
    while(m--) {
        G(u) G(v)
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1, 1, 1);
    F(i, 1, n + 1) for(ll j : backOut[i]) if(dep[i] - dep[j] < k) {
        vector<ll> cyc; ll v = i;
        while(1) { cyc.push_back(v); if(v == j) break; v = par[v]; }
        cout << "2\n" << cyc.size() << '\n';
        for(ll c : cyc) cout << c << ' '; EX('\n')
    }
    dfsInd(1, 0, 0);
}
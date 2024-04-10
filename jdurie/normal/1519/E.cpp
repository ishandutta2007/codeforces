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
typedef pair<ll, ll> pl;

#define G(x) ll x; cin >> x;
#define F(i, l, r) for(ll i = l; i < (r); ++i)
#define K first
#define V second
#define N 400010

vector<pl> graph[N], backOut[N], tree[N];
ll dep[N], par[N], pi[N];

void dfs(ll i, ll p) {
    par[i] = p;
    dep[i] = dep[p] + 1;
    for(pl j : graph[i]) if(j.V != pi[i]) {
        if(!dep[j.K]) {
            tree[i].push_back(j);
            pi[j.K] = j.V;
            dfs(j.K, i);
        } else if(dep[j.K] < dep[i])
            backOut[i].push_back(j);
    }
}

vector<pl> triples;

ll root;

bool fillTriples(ll i) {
    vector<pl> edges = backOut[i];
    for(pl j : tree[i])
        if(!fillTriples(j.K))
            edges.push_back(j);
    for(ll k = 0; k + 1 < edges.size(); k += 2)
        triples.emplace_back(edges[k].V, edges[k + 1].V);
    if((edges.size() & 1) && i != root)
        triples.emplace_back(edges.back().V, pi[i]);
    return edges.size() & 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(m) ll n = 0;
    map<pl, ll> getv;
    F(i, 0, m) {
        G(a) G(b) G(c) G(d)
        pl p1 = {a * d + b * d, b * c};
        pl p2 = {a * d, b * c + b * d};
        ll g1 = __gcd(p1.K, p1.V), g2 = __gcd(p2.K, p2.V);
        p1.K /= g1, p1.V /= g1, p2.K /= g2, p2.V /= g2;
        if(!getv.count(p1)) getv[p1] = ++n;
        if(!getv.count(p2)) getv[p2] = ++n;
        graph[getv[p1]].emplace_back(getv[p2], i);
        graph[getv[p2]].emplace_back(getv[p1], i);
    }
    F(i, 1, n + 1) if(!dep[i]) {
        pi[i] = -1;
        dfs(i, i);
        root = i;
        fillTriples(i);
    }
    cout << triples.size() << '\n';
    for(auto a : triples)
        cout << a.K + 1 << ' ' << a.V + 1 << '\n';
}
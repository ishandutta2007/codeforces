//DFS Tree
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pl;

#define G(x) ll x; cin >> x;
#define F(i, l, r) for(ll i = l; i < (r); ++i)
#define N 200010

vector<ll> graph[N], backIn[N], backOut[N], tree[N];
ll dep[N], par[N];

void dfs(ll i, ll p) {
    par[i] = p;
    dep[i] = dep[p] + 1;
    for(ll j : graph[i]) if(j - p) {
        if(!dep[j]) {
            tree[i].push_back(j);
            dfs(j, i);
        } else if(dep[j] < dep[i]) {
            backIn[j].push_back(i);
            backOut[i].push_back(j);
        }
    }
}

vector<tuple<ll, ll, ll>> triples;

ll root;

bool fillTriples(ll i) {
    vector<ll> edges = backOut[i];
    for(ll j : tree[i])
        if(!fillTriples(j))
            edges.push_back(j);
    for(ll k = 0; k + 1 < edges.size(); k += 2)
        triples.push_back({edges[k], i, edges[k + 1]});
    if((edges.size() & 1) && i != root)
        triples.push_back({edges.back(), i, par[i]});
    return edges.size() & 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) G(m)
    while(m--) {
        G(u) G(v)
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    F(i, 1, n + 1) if(!dep[i]) {
        dfs(i, i);
        root = i;
        fillTriples(i);
    }
    cout << triples.size() << '\n';
    for(auto a : triples)
        cout << get<0>(a) << ' ' << get<1>(a) << ' ' << get<2>(a) << '\n';
}
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define rep(i,n) for(int i=0;i<n;++i)
struct UnionFind {
    vector<int> par;

    UnionFind(int n) : par(n, -1) {}

    int root(int x) {
        if (par[x] < 0) return x;
        return par[x] = root(par[x]);
    }

    bool is_same(int x, int y) { return root(x) == root(y); }

    bool merge(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return true;
    }
};

struct edge{
    int u, v, cost;
};

long long solve() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<edge> es(M);
    rep(i,M){
        cin>>es[i].u>>es[i].v>>es[i].cost;
        --es[i].u;
        --es[i].v;
    }
    sort(es.begin(),es.end(),[](auto l,auto r){return l.cost<r.cost;});
    vector<int> sel;

    UnionFind dsu(N);
    rep(i,M){
        if(dsu.merge(es[i].u,es[i].v)){
            sel.emplace_back(es[i].cost);
        }
    }
    if(sel.back()<K){
        int ans=K;
        rep(i,M)ans=min(ans,abs(K-es[i].cost));
        return ans;
    }
    long long ans=0;
    for(auto x:sel){
        ans+=max(0,x-K);
    }
    return ans;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) cout<<solve()<<endl;
}
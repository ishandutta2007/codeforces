#include "bits/stdc++.h"
using namespace std;
#define all(x) begin(x),end(x)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
int diam=-1, leaf=-1;
vvi adj;
vi incomp,dep;
void dfs(int at, int from) {
    incomp.push_back(at);
    if(dep[at]>diam) {
        diam = dep[at];
        leaf=at;
    }
    for(auto to : adj[at]) if(to!=from) {
        dep[to]=dep[at]+1;
        dfs(to,at);
    }
}
template<typename T> auto getSum(const T& v, int l, int r) {
    int n = v.size();
    r = clamp(r,0,n-1);
    l = clamp(l,0, n-1);
    auto tmp = v[r];
    if(l>0) tmp-=v[l-1];
    return (double)tmp;
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,q; cin >> n >> m >> q;
    adj.resize(n), dep.resize(n);
    for(int i=0;i<m;++i) {
        int u,v; cin >> u >> v,--u,--v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vvi pref(n);
    vector<vector<ll>> EV(n);
    vi comp(n,-1),furthest(n,0),sz(n);
    auto runDFS = [&](int i) {
        incomp.clear();
        dep[i]=0, diam=-1,leaf=-1;
        dfs(i,-1);
    };
    for(int i=0;i<n;++i) if(comp[i]==-1) {
        runDFS(i);
        runDFS(leaf);
        pref[i].resize(diam+1);
        EV[i].resize(diam+1);
        for(auto j : incomp) {
            comp[j]=i;
            furthest[j] = dep[j];
        }
        runDFS(leaf);
        for(auto j : incomp) {
            furthest[j] = max(furthest[j],dep[j]);
            pref[i][furthest[j]]++;
            EV[i][furthest[j]]+=furthest[j];
            sz[i]++;
        }
        for(int j=1;j<=diam;++j) {
            pref[i][j]+=pref[i][j-1];
            EV[i][j]+=EV[i][j-1];
        }
    }
    map<pi,double> cache;

    while(q--) {
        int u,v; cin >> u >> v,--u,--v;
        u=comp[u],v=comp[v];
        if(u==v) {
            cout << "-1\n";
            continue;
        }
        if(pref[u].size()>pref[v].size()) swap(u,v);
        int szu = pref[u].size(),szv = pref[v].size();
        double total=0;
        if(cache.count({u,v})) {
            total = cache[{u,v}];
        } else {
            int lb = max(szu-1,szv-1);
            for(int i=0;i<szu;++i) {
                int j = lb-i;
                total+=getSum(pref[u],i,i)*getSum(EV[v],j,n);
                total+=getSum(pref[v],j,n)*getSum(EV[u],i,i);
                total+=getSum(pref[u],i,i)*getSum(pref[v],j,n);
                total+=lb*getSum(pref[u],i,i)*getSum(pref[v],0,j-1);
            }
            total/=(double)sz[u]*sz[v];
            cache[{u,v}]=total;
        }
        cout << setprecision(15) << total << '\n';

    }
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int in[300005];
int low[300005];

int tajm;
int cnt;

bool visited[300005];
int comp[300005];

vector <int> graf[300005];
vector <int> dgraf[300005];
vector <int> tree[300005];

void dfs1(int v, int parent){
    in[v] = ++tajm;
    visited[v] = 1;
    low[v] = in[v];
    for(auto c : graf[v]){
        if(c == parent) continue;
        if(visited[c]){
            dgraf[c].push_back(v);
            dgraf[v].push_back(c);
            low[v] = min(low[v], in[c]);
            continue;
        }
        dfs1(c, v);
        low[v] = min(low[v], low[c]);
    }
    if(!parent) return;
    if(low[v] <= in[parent]){
        dgraf[v].push_back(parent);
        dgraf[parent].push_back(v);
    }
}

vector <pair <int, int>> edges;

void dfs2(int v){
    comp[v] = cnt;
    visited[v] = 1;
    for(auto c : dgraf[v]){
        if(!visited[c]) dfs2(c);
    }
}

int mxdist, far;

void dfs3(int v, int dist, int parent){
    if(dist > mxdist){
        far = v;
        mxdist = dist;
    }
    for(auto c : tree[v]){
        if(c == parent) continue;
        dfs3(c, dist+1, v);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n, m;
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        int a, b;
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
        edges.push_back({a, b});
    }
    dfs1(1, 0);
    for(int i=1; i<=n; i++){
        visited[i] = 0;
    }
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            cnt++;
            dfs2(i);
        }
    }
    for(auto c : edges){
        if(comp[c.first] != comp[c.second]){
            tree[comp[c.first]].push_back(comp[c.second]);
            tree[comp[c.second]].push_back(comp[c.first]);
        }
    }
    far = 1;
    dfs3(1, 0, 0);
    mxdist = 0;
    dfs3(far, 0, 0);
    cout << mxdist << "\n";
    return 0;
}
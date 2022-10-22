#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 1000000000000000000LL;

ll dist[100005];
int od[100005];

int n, k;

struct edge{
    int a, b;
    ll c;
};

vector <edge> edges;
vector <pair <int, int>> graf[100005];

void dijkstra(){
    for(int i=k+1; i<=n; i++){
        dist[i] = INF;
    }
    set <pair <ll, int>> q;
    for(int i=1; i<=k; i++){
        od[i] = i;
        q.insert({0, i});
    }
    while(!q.empty()){
        pair <ll, int> par = *q.begin();
        q.erase(q.begin());
        int v = par.second;
        for(auto g : graf[v]){
            int c = g.first;
            int x = g.second;
            if(dist[v] + x < dist[c]){
                q.erase({dist[c], c});
                dist[c] = dist[v] + x;
                od[c] = od[v];
                q.insert({dist[c], c});
            }
        }
    }
}

bool cmp(edge a, edge b){
    return a.c < b.c;
}

int pr[100005];
int sz[100005];
vector <pair <int, ll>> tree[100005];

int root(int v){
    if(pr[v] == v) return v;
    return pr[v] = root(pr[v]);
}

void unite(int a, int b, ll c){
    int a1 = root(a);
    int b1 = root(b);
    if(a1 == b1) return;
    tree[a].push_back({b, c});
    tree[b].push_back({a, c});
    if(sz[a1] < sz[b1]) swap(a1, b1);
    sz[a1] += sz[b1];
    pr[b1] = a1;
}

void mst(){
    sort(edges.begin(), edges.end(), cmp);
    for(int i=1; i<=k; i++){
        pr[i] = i;
        sz[i] = 1;
    }
    for(auto edge : edges){
        int a = edge.a;
        int b = edge.b;
        ll c = edge.c;
        unite(a, b, c);
    }
}

int par[100005][20];
ll mxw[100005][20];

int trm;

int in[100005];
int out[100005];

void dfs(int v, int parent){
    in[v] = ++trm;
    for(int j=1; j<20; j++){
        par[v][j] = par[par[v][j-1]][j-1];
        mxw[v][j] = max(mxw[v][j-1], mxw[par[v][j-1]][j-1]);
    }
    for(auto g : tree[v]){
        int c = g.first;
        if(c == parent) continue;
        par[c][0] = v;
        mxw[c][0] = g.second;
        dfs(c, v);
    }
    out[v] = ++trm;
}

bool is_parent(int a, int b){
    return in[a] <= in[b] && out[b] <= out[a];
}

int lca(int a, int b){
    if(is_parent(a, b)) return a;
    for(int j=19; j>=0; j--){
        if(par[a][j] && !is_parent(par[a][j], b)){
            a = par[a][j];
        }
    }
    return par[a][0];
}

ll weight(int a, int b){
    ll res = 0;
    for(int j=19; j>=0; j--){
        if(par[a][j] && !is_parent(par[a][j], b)){
            res = max(res, mxw[a][j]);
            a = par[a][j];
        }
    }
    if(a != b) res = max(res, mxw[a][0]);
    return res;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int m, q;
    cin >> n >> m >> k >> q;
    for(int i=1; i<=m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graf[a].push_back({b, c});
        graf[b].push_back({a, c});
    }
    dijkstra();
    for(int i=1; i<=n; i++){
        for(auto c : graf[i]){
            edges.push_back({od[i], od[c.first], dist[i] + dist[c.first] + c.second});
        }
    }
    mst();
    dfs(1, 0);
    while(q--){
        int a, b;
        cin >> a >> b;
        int x = lca(a, b);
        cout << max(weight(a, x), weight(b, x)) << "\n";
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MAXN = 100000;

int pr[MAXN+5];
int sz[MAXN+5];

ll dist[25][MAXN+5];

vector <pair <int, int>> graf[MAXN+5];
vector <pair <int, int>> drvo[MAXN+5];

const int MAXLOG = 18;

int in[MAXN+5];
int out[MAXN+5];
int par[MAXN+5][MAXLOG+1];
ll val[MAXN+5][MAXLOG+1];

int tjm;

void dfs(int v, int p, int d){
    in[v] = ++tjm;
    par[v][0] = p;
    val[v][0] = d;
    for(int j=1; j<=MAXLOG; j++){
        par[v][j] = par[par[v][j-1]][j-1];
        val[v][j] = val[v][j-1] + val[par[v][j-1]][j-1];
    }
    for(auto c : drvo[v]){
        if(c.first == p) continue;
        dfs(c.first, v, c.second);
    }
    out[v] = tjm;
}

bool is_parent(int a, int b){
    return a == 0 || (in[a] <= in[b] && out[b] <= out[a]);
}

int root(int x){
    if(pr[x] == x) return x;
    return pr[x] = root(pr[x]);
}

int lca(int a, int b){
    if(is_parent(a, b)) return a;
    for(int j=MAXLOG; j>=0; j--) if(!is_parent(par[a][j], b)) a = par[a][j];
    return par[a][0];
}

ll rast(int a, int b){
    int x = lca(a, b);
    ll res = 0;
    for(int j=MAXLOG; j>=0; j--){
        if(!is_parent(par[a][j], x)){
            res += val[a][j];
            a = par[a][j];
        }
    }
    if(a != x) res += val[a][0];
    for(int j=MAXLOG; j>=0; j--){
        if(!is_parent(par[b][j], x)){
            res += val[b][j];
            b = par[b][j];
        }
    }
    if(b != x) res += val[b][0];
    return res;
}

const ll INF = 10000000000000000LL;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n, m;
    cin >> n >> m;
    vector <int> koji;
    for(int i=1; i<=n; i++){
        pr[i] = i, sz[i] = 1;
    }
    for(int i=1; i<=m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        int a1 = root(a);
        int b1 = root(b);
        graf[a].push_back({b, c});
        graf[b].push_back({a, c});
        if(a1 == b1){
            koji.push_back(a);
            continue;
        }
        drvo[a].push_back({b, c});
        drvo[b].push_back({a, c});
        if(sz[a1] < sz[b1]) swap(a1, b1);
        sz[a1] += sz[b1];
        pr[b1] = a1;
    }
    dfs(1, 0, 0);
    int cnt = koji.size();
    for(int i=0; i<cnt; i++){
        for(int v=1; v<=n; v++) dist[i][v] = INF;
        dist[i][koji[i]] = 0;
        set <pair <ll, int>> q;
        q.insert({0, koji[i]});
        while(!q.empty()){
            int v = q.begin()->second;
            q.erase(q.begin());
            for(auto prr : graf[v]){
                int c = prr.first;
                int d = prr.second;
                if(dist[i][c] > dist[i][v] + d){
                    q.erase({dist[i][c], c});
                    dist[i][c] = dist[i][v] + d;
                    q.insert({dist[i][c], c});
                }
            }
        }
    }
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        ll res = rast(a, b);
        for(int i=0; i<cnt; i++) res = min(res, dist[i][a] + dist[i][b]);
        cout << res << "\n";
    }
    return 0;
}
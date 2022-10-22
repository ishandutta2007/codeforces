#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

struct edge{
    int a, b, c;
    bool operator <(const edge &e){
        return c < e.c;
    }
};

vector <pair <int, int>> graf[200005];
int sz[200005];
int pr[200005];
int par[200005][20];
int val[200005][20];
int in[200005];
int out[200005];

ll sum;

int root(int x){
    if(x == pr[x]) return x;
    return pr[x] = root(pr[x]);
}

void dodaj(int a, int b, int c){
    int a1 = root(a);
    int b1 = root(b);
    if(a1 == b1) return;
    graf[a].push_back({b, c});
    graf[b].push_back({a, c});
    if(sz[a1] < sz[b1]) swap(a1, b1);
    sz[a1] += sz[b1];
    pr[b1] = a1;
    sum += c;
}

int tjm;

void dfs(int v, int p, int d){
    par[v][0] = p;
    val[v][0] = d;
    in[v] = ++tjm;
    for(int i=1; i<=18; i++){
        par[v][i] = par[par[v][i-1]][i-1];
        val[v][i] = max(val[v][i-1], val[par[v][i-1]][i-1]);
    }
    for(auto c : graf[v]) if(c.first != p) dfs(c.first, v, c.second);
    out[v] = ++tjm;
}

int ea[200005];
int eb[200005];
int ec[200005];

vector <edge> edges;

bool is_parent(int a, int b){
    return (a == 0) || (in[a] <= in[b] && out[b] <= out[a]);
}

int lca(int a, int b){
    if(is_parent(a, b)) return a;
    for(int j=18; j>=0; j--) if(!is_parent(par[a][j], b)) a = par[a][j];
    return par[a][0];
}

int kveri(int a, int b){
    int x = lca(a, b);
    int res = 0;
    if(x != a){
        for(int j=18; j>=0; j--){
            if(!is_parent(par[a][j], x)){
                res = max(res, val[a][j]);
                a = par[a][j];
            }
        }
        res = max(res, val[a][0]);
    }
    if(x != b){
        for(int j=18; j>=0; j--){
            if(!is_parent(par[b][j], x)){
                res = max(res, val[b][j]);
                b = par[b][j];
            }
        }
        res = max(res, val[b][0]);
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        sz[i] = 1;
        pr[i] = i;
    }
    for(int i=1; i<=m; i++){
        cin >> ea[i] >> eb[i] >> ec[i];
        edges.push_back({ea[i], eb[i], ec[i]});
    }
    sort(edges.begin(), edges.end());
    for(auto d : edges){
        dodaj(d.a, d.b, d.c);
    }
    dfs(1, 0, 0);
    for(int i=1; i<=m; i++){
        cout << sum + ec[i] - kveri(ea[i], eb[i]) << "\n";
    }
    return 0;
}
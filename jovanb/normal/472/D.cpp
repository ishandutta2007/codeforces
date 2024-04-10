#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int mat[2005][2005];

struct edge{
    int a, b, c;
};

vector <edge> edges;

bool cmp(edge a, edge b){
    return a.c < b.c;
}

int par[2005];
int sz[2005];

int root(int x){
    if(par[x] == x) return x;
    return par[x] = root(par[x]);
}

void mrg(int a, int b){
    if(sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    par[b] = a;
}

vector <pair <int, int>> graf[2005];
ll dist[2005];

int n;

const ll INF = 1000000000000000000LL;

void bfs(int root){
    queue <int> q;
    for(int i=1; i<=n; i++) dist[i] = INF;
    dist[root] = 0;
    q.push(root);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(auto c : graf[v]){
            if(dist[c.first] == INF){
                dist[c.first] = c.second + dist[v];
                q.push(c.first);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout << fixed;
    
    cin >> n;
    for(int i=1; i<=n; i++){
        sz[i] = 1;
        par[i] = i;
        for(int j=1; j<=n; j++){
            cin >> mat[i][j];
            if(i < j) edges.push_back({i, j, mat[i][j]});
        }
    }
    for(int i=1; i<=n; i++){
        if(mat[i][i]){
            cout << "NO\n";
            return 0;
        }
        for(int j=1; j<=n; j++){
            if(mat[i][j] != mat[j][i]){
                cout << "NO\n";
                return 0;
            }
            if(j != i && mat[i][j] == 0){
                cout << "NO\n";
                return 0;
            }
        }
    }
    sort(edges.begin(), edges.end(), cmp);
    for(auto c : edges){
        int a = c.a;
        int b = c.b;
        int a1 = root(a);
        int b1 = root(b);
        //cout << "izmedju " << a << " " << b << " " << c.c << endl;
        if(a1 != b1){
            graf[a].push_back({b, c.c});
            graf[b].push_back({a, c.c});
            mrg(a1, b1);
        }
        /*else{
            bfs(a);
            //cout << a << " " << dist[b] << endl;
            if(dist[b] != c.c){
                cout << "NO\n";
                return 0;
            }
        }*/
    }
    for(int i=1; i<=n; i++){
        bfs(i);
        for(int j=1; j<=n; j++){
            if(dist[j] != mat[i][j]){
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES\n";
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int dist[100005];

const int INF = 1000000000;

int mx = 0;

vector <int> graf[100005];

void dfs(int v, int par){
    if(dist[v] > dist[mx]){
        mx = v;
    }
    for(auto c : graf[v]){
        if(c != par){
            dist[c] = dist[v]+1;
            dfs(c, v);
        }
    }
}

void cleardist(int n){
    for(int i=1; i<=n; i++) dist[i] = INF;
}

bool solve(){
    int n, a, b, da, db;
    cin >> n >> a >> b >> da >> db;
    for(int i=1; i<=n; i++){
        graf[i].clear();
    }
    for(int i=1; i<n; i++){
        int x, y;
        cin >> x >> y;
        graf[x].push_back(y);
        graf[y].push_back(x);
    }
    if(2*da >= db) return 1;
    cleardist(n);
    mx = a;
    dist[a] = 0;
    dfs(a, 0);
    if(dist[b] <= da) return 1;
    cleardist(n);
    int g = mx;
    dist[mx] = 0;
    dfs(g, 0);
    int dij = dist[mx];
    dij = (dij+1)/2;
    if(da >= dij) return 1;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    while(t--){
        if(solve()) cout << "Alice\n";
        else cout << "Bob\n";
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 200000;
const int INF = 1000000000;

int dist[N+5];
int deg[N+5];

vector <int> graf[N+5];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n, m;
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        int u, v;
        cin >> u >> v;
        graf[v].push_back(u);
        deg[u]++;
    }
    priority_queue <pair <int, int>, vector <pair <int, int>>, greater <pair <int, int>>> q;
    for(int i=1; i<n; i++) dist[i] = INF;
    q.push({0, n});
    while(!q.empty()){
        int d, v;
        tie(d, v) = q.top();
        q.pop();
        if(d != dist[v]) continue;
        for(auto c : graf[v]){
            deg[c]--;
            if(dist[c] > d + deg[c] + 1){
                dist[c] = d + deg[c] + 1;
                q.push({dist[c], c});
            }
        }
    }
    cout << dist[1] << "\n";
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
constexpr int maxn = 200000;
vector<int> G[maxn + 1];
int p[maxn + 1], d[maxn + 1], c[maxn + 1];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for(int i = 0, u, v; i < m; i += 1){
        cin >> u >> v;
        G[v].push_back(u);
    }
    int k;
    cin >> k;
    for(int i = 1; i <= k; i += 1) cin >> p[i];
    fill(d + 1, d + n + 1, maxn);
    queue<int> q;
    d[p[k]] = 0;
    q.push(p[k]);
    while(not q.empty()){
        int u = q.front();
        q.pop();
        for(int v : G[u]) if(d[v] == maxn){
            d[v] = d[u] + 1;
            q.push(v);
        }
    }
    for(int i = 1; i <= n; i += 1) for(int j : G[i]) if(d[i] + 1 == d[j]) c[j] += 1;
    //for(int i = 1; i <= n; i += 1) cout << i << " " << c[i] << " " << d[i] << endl;
    int min = 0, max = 0;
    for(int i = 1; i < k; i += 1){
        if(d[p[i]] != d[p[i + 1]] + 1) min += 1;
        if(d[p[i]] != d[p[i + 1]] + 1 or c[p[i]] > 1) max += 1;
    }
    cout << min << " " << max;
    return 0;
}
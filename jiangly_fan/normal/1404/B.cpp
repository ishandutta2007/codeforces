#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 100000 + 1;
vector<int> G[maxn];
int d[maxn];
void DFS(int u, int pa = 0){
    for(int v : G[u]) if(v != pa){
        d[v] = d[u] + 1;
        DFS(v, u);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n, a, b, da, db;
        cin >> n >> a >> b >> da >> db;
        for(int i = 1; i <= n; i += 1) G[i].clear();
        for(int i = 1, u, v; i < n; i += 1){
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        if(db <= da * 2){
            cout << "Alice\n";
            continue;
        }
        d[a] = 0;
        DFS(a);
        if(d[b] <= da){
            cout << "Alice\n";
            continue;
        }
        int r = max_element(d + 1, d + n + 1) - d;
        d[r] = 0;
        DFS(r);
        int D = *max_element(d + 1, d + n + 1);
        if(D <= 2 * da) cout << "Alice\n";
        else cout << "Bob\n";
    }
    return 0;
}
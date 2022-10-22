#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll val[200001][2];
ll depe[200001][2];
vector<vector<int>> adj;

void dfs(int n, int par) {
    for(int i : adj[n]) {
        if(i == par) continue;
        dfs(i, n);
    }
    ll ans1, ans2;
    ans1 = ans2 = 0;
    for(int i : adj[n]) {
        if(i == par) continue;
        ans1 += max(depe[i][0] + abs(val[i][0] - val[n][0]), depe[i][1] + abs(val[i][1] - val[n][0]));
        ans2 += max(depe[i][0] + abs(val[i][0] - val[n][1]), depe[i][1] + abs(val[i][1] - val[n][1])); 
    }
    depe[n][0] = ans1; depe[n][1] = ans2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        adj.resize(n);
        for(int i = 0; i < n; i++) {
            cin >> val[i][0] >> val[i][1];
            depe[i][0] = depe[i][1] = 0;
        }
        for(int i = 1; i < n; i++) {
            int x, y;
            cin >> x >> y;
            x--; y--;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        dfs(0, -1);
        cout << max(depe[0][0], depe[0][1]) << '\n';
        vector<vector<int>>().swap(adj);
    }
}
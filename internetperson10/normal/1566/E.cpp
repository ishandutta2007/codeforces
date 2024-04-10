#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

vector<vector<int>> adj;
int w, z;

bool dfs(int n, int par = -1) {
    bool num = true;
    for(int ch : adj[n]) {
        if(ch == par) continue;
        num &= dfs(ch, n);
    }
    if(par != -1) {
        if(num) z++;
        else w++;
    }
    else {
        if(num) z++;
    }
    return !num;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        adj.resize(n);
        w = z = 0;
        for(int i = 1; i < n; i++) {
            int x, y;
            cin >> x >> y;
            x--; y--;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        dfs(0);
        cout << z - w << '\n';
        vector<vector<int>>().swap(adj);
    }
}
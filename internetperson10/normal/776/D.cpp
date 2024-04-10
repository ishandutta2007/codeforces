#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

vector<vector<int>> edges;
vector<int> wts, nums;
vector<vector<pair<int, int>>> adj;

void dfs(int x) {
    for(auto p : adj[x]) {
        int ch, w;
        tie(ch, w) = p;
        if(nums[ch] == -1) {
            nums[ch] = nums[x] ^ w;
            dfs(ch);
        }
    }
}

// Number of 0s in each connected component is even.
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m, n;
    cin >> m >> n;
    edges.resize(m);
    wts.resize(m);
    for(int i = 0; i < m; i++) {
        cin >> wts[i];
        wts[i] = 1 - wts[i];
    }
    for(int z = 0; z < n; z++) {
        int x;
        cin >> x;
        while(x--) {
            int y;
            cin >> y;
            y--;
            edges[y].push_back(z);
        }
    }
    adj.resize(n);
    for(int i = 0; i < m; i++) {
        int x = edges[i][0];
        int y = edges[i][1];
        adj[x].push_back({y, wts[i]});
        adj[y].push_back({x, wts[i]});
    }
    nums.resize(n, -1);
    for(int i = 0; i < n; i++) {
        if(nums[i] == -1) {
            nums[i] = 0;
            dfs(i);
        }
    }
    bool ok = true;
    for(int i = 0; i < m; i++) {
        int x = edges[i][0];
        int y = edges[i][1];
        if((nums[x] ^ nums[y]) != wts[i]) ok = false;
    }
    if(ok) cout << "YES\n";
    else cout << "NO\n";
}
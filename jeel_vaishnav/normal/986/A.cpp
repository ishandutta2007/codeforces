#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m, k, s;
    cin >> n >> m >> k >> s;

    int a[n];
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i]--;
    } 
    vector<int> adj[n];
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int vis[n][k];
    int cnt[n];
    int cost[n];
    for(int i = 0; i < n; ++i) {
        cost[i] = 0;
        cnt[i] = 0;
        for(int j = 0; j < k; ++j)
            vis[i][j] = 0;
    }
    queue<pair<int, int>> queue;
    for(int i = 0; i < n; ++i) {
        queue.push(make_pair(i, a[i]));
        vis[i][a[i]] = 1;
    }

    int ccost = 0;
    while(!queue.empty()) {
        int round = queue.size();
        for(int i = 0; i < round; ++i) {
            pair<int, int> curp = queue.front();
            queue.pop();
            int cur = curp.first, type = curp.second;
            if(cnt[cur] < s) {
                cnt[cur]++;
                cost[cur] += ccost; 
            }
            for(int j : adj[cur]) {
                if(vis[j][type] == 0) {
                    queue.push(make_pair(j, type));
                    vis[j][type] = 1;
                }
            }
        }
        ccost++;
    }

    for(int i = 0; i < n; ++i)
        cout << cost[i] << " ";
    
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long

bool dfs(int a, int L, vector<vector<int>>& g, vector<int>& btoa, vector<int>& A, vector<int>& B) {
    if (A[a] != L) return 0;
    A[a] = -1;
    for (int b : g[a]) if (B[b] == L + 1) {
        B[b] = 0;
        if (btoa[b] == -1 || dfs(btoa[b], L + 1, g, btoa, A, B))
            return btoa[b] = a, 1;
    }
    return 0;
}
int hopcroftKarp(vector<vector<int>>& g, vector<int>& btoa) {//btoa is just array of -1 size n, g is the adjacency list
    int res = 0;
    vector<int> A(g.size()), B(btoa.size()), cur, next;
    for (;;) {
        fill(A.begin(),A.end(), 0);
        fill(B.begin(),B.end(), 0);
        /// Find the starting nodes for BFS (i.e. layer 0).
        cur.clear();
        for (int a : btoa) if(a != -1) A[a] = -1;
        for(int a = 0; a<g.size(); a++) if(A[a] == 0) cur.push_back(a);
        /// Find all layers using bfs.
        for (int lay = 1;; lay++) {
            bool islast = 0;
            next.clear();
            for (int a : cur) for (int b : g[a]) {
                if (btoa[b] == -1) {
                    B[b] = lay;
                    islast = 1;
                }
                else if (btoa[b] != a && !B[b]) {
                    B[b] = lay;
                    next.push_back(btoa[b]);
                }
            }
            if (islast) break;
            if (next.empty()) return res;
            for (int a : next) A[a] = lay;
            cur.swap(next);
        }
        /// Use DFS to scan for augmenting paths.
        for(int a = 0; a<g.size(); a++)
            res += dfs(a, 0, g, btoa, A, B);
    }
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,m;
    cin >> n >> m;
    vector<vector<int>>adj(1001);
    for(int i = 0; i<m; i++){
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<vector<int>>dis(n+1,vector<int>(n+1,(int)1e18));
    for(int i = 1; i<=n; i++){
        queue<int>q;
        vector<bool>vis(n+1);
        q.push(i); vis[i] = true; dis[i][i] = 0;
        while(!q.empty()){
            int cur = q.front(); q.pop();
            for(int nxt: adj[cur]){
                if(!vis[nxt]){
                    vis[nxt] = true;
                    dis[i][nxt] = dis[i][cur]+1;
                    q.push(nxt);
                }
            }
        }
    }
    vector<int>val(1001,-1);
    for(int i = 1; i<=1000; i++){
        adj[i].clear();
    }
    int s,b,k,h;
    cin >> s >> b >> k >> h;
    vector<vector<int>>arr(s+1,vector<int>(3));
    for(int i = 1; i<=s; i++){
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
    for(int i = 1; i<=b; i++){
        int x,d;
        cin >> x >> d;
        for(int j = 1; j<=s; j++){
            if(dis[x][arr[j][0]]<=arr[j][2]&&arr[j][1]>=d){
                adj[j].push_back(i);
            }
        }
    }
    int v = hopcroftKarp(adj,val);
    cout << min(v*k,s*h) << "\n";
	return 0;
}
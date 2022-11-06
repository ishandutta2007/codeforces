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
	vector<int>arr(n+1);
	for(int i = 1; i<=n; i++){
		cin >> arr[i];
	}
	int cur = 1;
	vector<vector<pair<int,int>>>pf(n+1);
	for(int i = 1; i<=n; i++){
		int k = arr[i];
		for(int j = 2; j*j<=arr[i]; j++){
			while(k%j==0){
				k/=j;
				pf[i].push_back({j,cur});
				cur++;
			}
		}
		if(k>1){
			pf[i].push_back({k,cur});
			cur++;
		}
	}
	vector<vector<int>>adj(4000);
	vector<int>val(4000,-1);
	while(m--){
		int x,y;
		cin >> x >> y;
		if(y%2==1)swap(x,y);
		for(int i = 0; i<pf[x].size(); i++){
			for(int j = 0; j<pf[y].size(); j++){
				if(pf[x][i].first==pf[y][j].first){
					adj[pf[x][i].second].push_back(pf[y][j].second);
				}
			}
		}
	}
	cout << hopcroftKarp(adj,val) << "\n";
	return 0;
}
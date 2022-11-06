#include <bits/stdc++.h>
using namespace std;
#define int long long
//https://codeforces.com/blog/entry/57593 code from here
int n;
vector<vector<int>>adj(100001);
vector<int> Centroid(const vector<vector<int>> &g) {
        vector<int> centroid;
        vector<int> sz(n+2);
        function<void (int, int)> dfs = [&](int u, int prev) {
                sz[u] = 1;
                bool is_centroid = true;
                for (auto v : g[u]) if (v != prev) {
                        dfs(v, u);
                        sz[u] += sz[v];
                        if (sz[v] > n / 2) is_centroid = false;
                }
                if (n - sz[u] > n / 2) is_centroid = false;
                if (is_centroid) centroid.push_back(u);
        };
        dfs(1, -1);
        return centroid;
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		pair<int,int>f;
		for(int i = 1; i<=n; i++){
			adj[i].clear();
		}
		for(int i = 0; i<n-1; i++){
			int x,y;
			cin >> x >> y;
			if(i==0)f = {x,y};
			adj[x].push_back(y); adj[y].push_back(x);
		}
		vector<int> centroids = Centroid(adj);
		if(centroids.size()==1){
			cout << f.first << " " << f.second << "\n";
			cout << f.first << " " << f.second << "\n";
		}
		else{
			int a = centroids[0]; int b = centroids[1];
			for(int nxt: adj[a]){
				if(nxt!=b){
					cout << a << " " << nxt << "\n";
					cout << b << " " << nxt << "\n";
					break;
				}
			}
		}
	}
	return 0;
}
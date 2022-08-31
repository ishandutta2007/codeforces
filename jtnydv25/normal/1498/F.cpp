#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

#ifdef LOCAL
#include <print.h>
#else
#define trace(...)
#endif

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int n, k;
	cin >>n >> k;
	vector<vector<int>> adj(n);
	vector<vector<int>> down(n, vector<int>(2 * k + 1));
	vector<vector<int>> up(n, vector<int>(2 * k + 1));
	for(int i = 1; i < n; i++){
		int u, v; cin >> u >> v;
		adj[u - 1].push_back(v - 1);
		adj[v - 1].push_back(u - 1);
	}
	vector<int> a(n);
	for(int & x : a) cin >> x;
	function<void(int, int)> dfs = [&](int s, int p){
		down[s][0] = a[s];
		for(int v : adj[s]) if(v != p){
			dfs(v,s);
			for(int i = 0; i < 2 * k; i++){
				down[s][(i + 1) % (2 * k)]  ^= down[v][i];
			}
		}
	};

	dfs(0, -1);

	vector<int> eval(n);

	function<void(int, int)> dfs2 = [&](int s, int p){
		vector<int> sum(2 * k);
		if(p >= 0){
			sum = down[p];
			sum[0] ^= a[p];
			up[s][1] ^= a[p];
			for(int i = 0; i < 2 * k; i++){
				up[s][(i + 1) % (2 * k)] ^= up[p][i];
			}
			for(int i = 0; i < 2 * k; i++){
				int j = i - 1;
				if(j < 0) j += 2 * k;
				up[s][(i + 1) % (2 * k)] ^= sum[i] ^ down[s][j];
			}
		}
		for(int i = k; i < 2 * k; i++){
			eval[s] ^= down[s][i] ^ up[s][i];
		}
		for(int v : adj[s]) if(v != p) dfs2(v, s);
	};
	dfs2(0, -1);
	for(int i = 0; i < n; i++)cout << (eval[i] == 0 ? 0 : 1) << " ";
}
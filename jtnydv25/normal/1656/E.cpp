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
#define endl '\n' // remove in interactive
#endif

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int t; cin >> t;
	while(t--){
	int n; cin >> n;
	vector<vector<int>> adj(n);
	vector<int> a(n);
	for(int i = 1; i < n;i++){
		int u, v; cin >> u >> v;
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	// trace(n, adj);
	function<void(int, int, int)> dfs = [&](int s,int p, int sm){
		int sum = s == 0 ? 0 : sm;
		int val = 0;
		for(int v: adj[s]) if(v != p){
			dfs(v, s, sm * -1);
			val -= sm;
		}
		a[s] = sum - val;
	};
	dfs(0, 0, 1);
	for(int v = 0; v < n; v++) cout << a[v] <<" ";
	cout << endl;
	}
}
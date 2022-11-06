#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = (int)1e9+7;
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<vector<int>>adj(n+1);
		vector<int>arr(n+1);
		vector<int>arr2(n+1);
		vector<int>indices(n+1);
		vector<int>indices2(n+1);
		for(int i = 1; i<=n; i++){
			cin >> arr[i];
			indices[arr[i]] = i;
		}
		for(int i = 1; i<=n; i++){
			cin >> arr2[i];
			indices2[arr2[i]] = i;
		}
		for(int i = 1; i<=n; i++){
			adj[indices[i]].push_back(indices2[i]);
			adj[indices2[i]].push_back(indices[i]);
		}
		int ans = 1;
		vector<bool>vis(n+1);
		for(int i = 1; i<=n; i++){
			if(vis[i])continue;
			queue<int>q;
			q.push(i); vis[i] = true;
			while(!q.empty()){
				int cur = q.front(); q.pop();
				for(int nxt: adj[cur]){
					if(!vis[nxt]){
						vis[nxt] = true;
						q.push(nxt);
					}
				}
			}
			ans*=2; ans%=mod;
		}
		cout << ans << "\n";
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		vector<multiset<int>>arr(n);
		for(int i = 0; i<n; i++){
			for(int j = 0; j<m; j++){
				int x;
				cin >> x;
				arr[i].insert(x);
			}
		}
		vector<vector<bool>>vis(n,vector<bool>(m));
		vector<vector<int>>ans(n,vector<int>(m));
		for(int j = 0; j<m; j++){
			pair<int,int>low = {(int)1e18,0};
			for(int i = 0; i<n; i++){
				low = min(low,{*arr[i].begin(),i});
			}
			arr[low.second].erase(arr[low.second].lower_bound(low.first));
			vis[low.second][j] = low.first;
			ans[low.second][j] = low.first;
		}
		for(int i = 0; i<n; i++){
			for(int j = 0; j<m; j++){
				if(vis[i][j])continue;
				ans[i][j] = *arr[i].begin(); arr[i].erase(arr[i].begin());
			}
		}
		for(int i = 0; i<n; i++){
			for(int j = 0; j<m; j++){
				cout << ans[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
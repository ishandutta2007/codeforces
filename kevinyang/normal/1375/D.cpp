#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int>arr(n);
		for(int i = 0; i<n; i++){
			cin >> arr[i];
		}
		vector<int>ans;
		while(true){
			vector<bool>vis(n+1);
			for(int i = 0; i<n; i++){
				vis[arr[i]] = true;
			}
			bool works = true;
			int mex = n;
			for(int i = 0; i<n; i++){
				if(!vis[i]){
					works = false;
					mex = i;
					break;
				}
			}
			if(works){
				break;
			}
			ans.push_back(mex+1);
			arr[mex] = mex;
		}
		vector<bool>vis(n);
		for(int i = 0; i<n; i++){
			if(arr[i]==i)vis[i] = true;
		}
		vector<int>indices(n);
		for(int i = 0; i<n; i++){
			indices[arr[i]] = i;
		}
		while(true){
			bool f = true;
			for(int i = 0; i<n; i++){
				if(!vis[i])f = false;
			}
			if(f)break;
			int start = 0;
			for(int i = 0; i<n; i++){
				if(vis[i])continue;
				start = indices[i];
				break;
			}
			ans.push_back(start+1);
			int nxt = start;
			while(true){
				int mex = arr[nxt];
				nxt = mex;
				if(nxt==start){
					vis[nxt] = true;
					ans.push_back(nxt+1);
					break;
				}
				ans.push_back(nxt+1);
				vis[nxt] = true;
				
			}
		}
		cout << ans.size() << "\n";
		for(int nxt:ans){
			cout << nxt << " ";
		}
		cout << "\n";
	}
	return 0;
}
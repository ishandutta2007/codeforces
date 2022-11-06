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
		vector<vector<int>>adj(n+1);
		queue<int>q;
		vector<int>dis(n+1);
		int cur = 1; int ans = 0;
		for(int i = 1; i<n; i++){
			if(arr[i]<arr[i-1]){
				cur = q.front(); q.pop();
			}
			q.push(arr[i]); dis[arr[i]] = dis[cur]+1; ans = max(ans,dis[arr[i]]);
		}
		cout << ans << "\n";
	}
	return 0;
}
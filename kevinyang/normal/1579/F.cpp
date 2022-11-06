#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,d;
		cin >> n >> d;
		vector<int>arr(n);
		for(int i = 0; i<n; i++){
			cin >> arr[i];
		}
		vector<bool>vis(n);
		queue<int>q;
		vector<int>dis(n);
		for(int i = 0; i<n; i++){
			if(arr[i]==0){
				q.push(i);
				vis[i] = true;
			}
		}
		while(!q.empty()){
			int cur = q.front(); q.pop();
			int nxt = cur+d;
			nxt%=n;
			if(vis[nxt])continue;
			vis[nxt] = true;
			q.push(nxt);
			dis[nxt] = dis[cur]+1;
		}
		if(count(vis.begin(),vis.end(),false)>0){
			cout << "-1\n";
			continue;
		}
		int mx = 0;
		for(int i = 0; i<n; i++){
			mx = max(mx,dis[i]);
		}
		cout << mx << "\n";
	}
	return 0;
}
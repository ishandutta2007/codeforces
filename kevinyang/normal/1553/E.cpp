#include <bits/stdc++.h>
using namespace std;
#define int long long
int solve2(vector<int>arr, int delta){
	int n = arr.size()-1;
	int ans = n;
	vector<bool>vis(n+1);
	for(int i = 1; i<=n; i++){
		if(vis[i])continue;
		queue<int>q;
		q.push(i);
		ans--;
		vis[i] = true;
		while(!q.empty()){
			int cur = q.front(); q.pop();
			cur = arr[cur]-delta; cur+=n; cur%=n; if(cur==0) cur = n;
			if(vis[cur])break;
			q.push(cur);
			vis[cur] = true;
		}
	}
	return ans;
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		vector<int>arr(n+1);
		for(int i = 1; i<=n; i++){
			cin >> arr[i];
		}
		vector<int>freq(n+1);
		for(int i = 1; i<=n; i++){
			int dist = arr[i]-i; dist+=n;
			dist%=n;
			freq[dist]++;
		}
		vector<int>ans;
		for(int i = 0; i<n; i++){
			if(n-freq[i]<=2*m){
				int v = solve2(arr,i);
				if(v<=m)ans.push_back((n-i)%n);
			}
		}
		sort(ans.begin(),ans.end());
		cout << ans.size() << " ";
		for(int nxt: ans)cout << nxt << " ";
		cout << "\n";
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int>arr(n+1);
	vector<int>pointer(n+1);
	vector<bool>vis(n+1);
	vector<int>order;
	for(int i = 1; i<=n; i++){
		cin >> arr[i];
	}
	for(int i = 1; i<=n; i++){
		cin >> pointer[i];
	}
	queue<int>q;
	vector<int>indegrees(n+1);
	vector<vector<int>>dag(n+1);
	queue<int>q2;
	for(int i = 1; i<=n; i++){
		int y = pointer[i];
		if(y==-1){
			q2.push(i);
			continue;
		}
		indegrees[y]++;
		dag[y].push_back(i);
	}
	int ans = 0;
	for(int i = 1; i<=n; i++){
		if(indegrees[i]==0)q.push(i);
	}
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		int nxt = pointer[cur];
		if(nxt==-1){
			ans+=arr[cur];
			vis[cur] = true;
			order.push_back(cur);
		}
		else{
			if(arr[cur]>=0){
				vis[cur] = true;
				ans+=arr[cur];
				arr[nxt]+=arr[cur];
				order.push_back(cur);
			}
			indegrees[nxt]--;
			if(indegrees[nxt]==0)q.push(nxt);
		}
	}
	while(!q2.empty()){
		int cur = q2.front();
		q2.pop();
		for(int nxt: dag[cur]){
			q2.push(nxt);
		}
		if(!vis[cur]){
			order.push_back(cur);
			ans+=arr[cur];
		}
	}
	cout << ans << "\n";
	for(int nxt:order){
		cout << nxt << " ";
	}
	return 0;
}
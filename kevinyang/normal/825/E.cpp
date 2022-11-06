#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	vector<vector<int>>adj(n+1);
	vector<int>indegrees(n+1);
	for(int i = 0; i<m; i++){
		int x,y;
		cin >> x >> y;
		adj[y].push_back(x);
		indegrees[x]++;
	}
	priority_queue<int>pq;
	vector<int>ans;
	for(int i = 1; i<=n; i++){
		if(indegrees[i]==0){
			pq.push(i);
		}
	}
	while(pq.size()){
		int cur = pq.top(); pq.pop();
		ans.push_back(cur);
		for(int nxt: adj[cur]){
			indegrees[nxt]--;
			if(indegrees[nxt]==0){
				pq.push(nxt);
			}
		}
	}
	reverse(ans.begin(),ans.end());
	vector<int>ind(n+1);
	for(int i = 1; i<=n; i++){
		ind[ans[i-1]] = i;
	}
	for(int i = 1; i<=n; i++){
		cout << ind[i] << " ";
	}
	cout << "\n";
	return 0;
}
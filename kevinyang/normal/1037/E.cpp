#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,m,k;
	cin >> n >> m >> k;
	vector<int>deg(n+1);
	vector<pair<int,int>>edges(m+1);
	vector<set<int>>adj(n+1);
	for(int i = 1; i<=m; i++){
		int x,y;
		cin >> x >> y;
		edges[i] = {x,y};
		deg[x]++; deg[y]++;
		adj[x].insert(y);
		adj[y].insert(x);
	}
	vector<int>ans(m+1);
	int cnt = n;
	vector<bool>vis(n+1);
	queue<int>q;
	for(int i = 1; i<=n; i++){
		if(deg[i]<k){
			vis[i] = true;
			q.push(i);
		}
	}
	set<pair<int,int>>s;
	while(q.size()){
		int cur = q.front(); q.pop();
		for(int nxt: adj[cur]){
			if(vis[nxt])continue;
			adj[nxt].erase(cur);
			s.insert({cur,nxt});
			s.insert({nxt,cur});
			deg[nxt]--;
			if(deg[nxt]<k){
				q.push(nxt);
				vis[nxt] = true;
			}
		}
		adj[cur].clear();
		deg[cur] = 0;
		cnt--;
	}
	ans[m] = cnt;
	for(int i = m; i>1; i--){
		int x = edges[i].first; int y = edges[i].second;
		if(s.find({x,y})!=s.end()||s.find({y,x})!=s.end()){
			ans[i-1] = cnt;
			continue;
		}
		s.insert({x,y});
		s.insert({y,x});
		deg[x]--; deg[y]--;
		adj[x].erase(y); adj[y].erase(x);
		//cout << deg[x] << " " << deg[y] << "\n";
		if(deg[x]<k&&!vis[x]){
			vis[x] = true; q.push(x);
		}
		if(deg[y]<k&&!vis[y]){
			vis[y] = true;
			q.push(y);
		}
		while(q.size()){
			int cur = q.front(); q.pop();
			for(int nxt: adj[cur]){
				if(vis[nxt])continue;
				s.insert({cur,nxt});
				s.insert({nxt,cur});
				adj[nxt].erase(cur);
				deg[nxt]--;
				if(deg[nxt]<k){
					q.push(nxt);
					vis[nxt] = true;
				}
			}
			adj[cur].clear();
			deg[cur] = 0;
			cnt--;
		}
		ans[i-1] = cnt;
	}
	for(int i = 1; i<=m; i++){
		cout << ans[i] << "\n";
	}
	return 0;
}
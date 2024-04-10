#include <bits/stdc++.h>
using namespace std;
#define int long long
struct DisjointSet{
	vector<int>parent,sz;
	int size;
	void init(int n){
		size = n;
		parent.resize(n+1); sz.resize(n+1);
		for(int i = 1; i<=n; i++){
			parent[i] = i;
			sz[i] = 1;
		}
	}
	int find(int x){
		if(parent[x]==x)return x;
		return find(parent[x]);
	}
	void Union(int x, int y){
		x = find(x); y = find(y);
		if(x==y)return;
		if(sz[x]<sz[y]){
			parent[x] = y;
			sz[y]+=sz[x];
		}
		else{
			parent[y] = x;
			sz[x]+=sz[y];
		}
	}
};
int n,m,Q;
const int mxn = 100005;
vector<vector<int>>adj(mxn);
vector<int>dis(mxn);
vector<bool>vis2(mxn);
vector<int>dis2(mxn);
vector<bool>vis3(mxn);
vector<int>dis3(mxn);
vector<bool>vis(mxn);
vector<int>di(mxn);
vector<int>dp(mxn);
vector<bool>vis1(mxn);
const int sq = 350;
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> m >> Q;
	for(int i = 0; i<m; i++){
		int x,y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for(int i = 1; i<=n; i++){
		if(vis[i])continue;
		queue<int>q;
		q.push(i);
		vis[i] = true;
		int mxlen = 0; int start = i;
		while(q.size()){
			int cur = q.front(); q.pop();
			for(int nxt: adj[cur]){
				if(vis[nxt])continue;
				vis[nxt] = true;
				dis[nxt] = dis[cur]+1;
				if(dis[nxt]>mxlen){
					mxlen = dis[nxt];
					start = nxt;
				}
				q.push(nxt);
			}
		}
		q.push(start);
		int dia = 0;
		int end = 0;
		vis2[start] = true;
		while(q.size()){
			int cur = q.front(); q.pop();
			for(int nxt: adj[cur]){
				if(vis2[nxt])continue;
				vis2[nxt] = true;
				dis2[nxt] = dis2[cur]+1;
				if(dia<dis2[nxt]){
					dia = dis2[nxt];
					end = nxt;
				}
				q.push(nxt);
			}
		}
		vis3[end] = true;
		q.push(end);
		while(q.size()){
			int cur = q.front(); q.pop();
			di[cur] = dia;
			for(int nxt: adj[cur]){
				if(vis3[nxt])continue;
				vis3[nxt] = true;
				dis3[nxt] = dis3[cur]+1;
				q.push(nxt);
			}
		}
	}
	for(int i = 1; i<=n; i++){
		dp[i] = max(dis3[i],dis2[i]);
		//cout << dis3[i] << " ";
	}
	cout << "\n";
	DisjointSet ds;
	ds.init(n);
	for(int i = 1; i<=n; i++){
		for(int nxt: adj[i]){
			ds.Union(i,nxt);
		}
	}
	vector<vector<int>>sets(n+1);
	for(int i = 1; i<=n; i++){
		sets[ds.find(i)].push_back(i);
	}
	vector<vector<pair<int,double>>>pre(n+1);//smaller component is index of pre and it contains all sqrt
	// + size components with the answer
	for(int i = 1; i<=n; i++){
		if(sets[i].size()>=sq){
			vector<int>sz;
			sz.push_back(-(int)1e9);
			for(int nxt: sets[i]){
				sz.push_back(dp[nxt]);
			}
			sort(sz.begin(),sz.end());
			vector<int>psa(sz.size());
			for(int i = 1; i<sz.size(); i++){
				psa[i] = psa[i-1]+sz[i];
			}
			for(int j = 1; j<=n; j++){
				if(sets[j].size()&&j!=i){
					int ans = 0;
					int mx = max(di[i],di[sets[j][0]]);
					for(int nxt: sets[j]){
						int idx = lower_bound(sz.begin(),sz.end(),mx-dp[nxt]-1)-sz.begin();
						int sum = 0;
						if(idx!=sz.size()){
							sum+=psa.back()-psa[idx-1]+(dp[nxt]+1)*((int)sz.size()-idx);
						}
						sum+=(idx-1)*mx;
						ans+=sum;
					}
					double ret = (double)ans/((int)sets[i].size()*(int)sets[j].size());
					pre[j].push_back({i,ret});
				}
			}
		}
	}
	cout << fixed << setprecision(10);
	while(Q--){
		int u,v;
		cin >> u >> v;
		if(ds.find(u)==ds.find(v)){
			cout << "-1\n";
			continue;
		}
		u = ds.find(u); v = ds.find(v);
		if(ds.sz[u]>ds.sz[v]){
			swap(u,v);
		}
		bool f = false;
		pair<int,double>p = {0,0};
		for(auto nxt: pre[u]){
			if(nxt.first==v){
				f = true;
				p = nxt;
			}
		}
		if(f){
			cout << p.second << "\n";
		}
		else{
			int i = u;
			int j = v;
			vector<int>sz;
			sz.push_back(-(int)1e9);
			for(int nxt: sets[i]){
				sz.push_back(dp[nxt]);
			}
			sort(sz.begin(),sz.end());
			vector<int>psa(sz.size());
			for(int i = 1; i<sz.size(); i++){
				psa[i] = psa[i-1]+sz[i];
			}
			int ans = 0;
			int mx = max(di[i],di[j]);
			for(int nxt: sets[j]){
				int idx = lower_bound(sz.begin(),sz.end(),mx-dp[nxt]-1)-sz.begin();
				int sum = 0;
				if(idx!=sz.size()){
					sum+=psa.back()-psa[idx-1]+(dp[nxt]+1)*((int)sz.size()-idx);
				}
				sum+=(idx-1)*mx;
				ans+=sum;
			}
			double ret = (double)ans/((int)sets[i].size()*(int)sets[j].size());
			cout << ret << "\n";
		}
	}
	return 0;
}
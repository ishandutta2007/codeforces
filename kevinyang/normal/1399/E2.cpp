#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<pair<int,int>>>adj(100001);
vector<int>wt(100001);
vector<bool>leaf(100001);
int n,s;
map<pair<int,int>,int>hm;
vector<int>one;
vector<int>two;
void dfs(int u, int p, int w){
	int children = 0;
	for(pair<int,int>nxt: adj[u]){
		if(nxt.second==p)continue;
		dfs(nxt.second,u,nxt.first);
		wt[u]+=wt[nxt.second];
		children++;
	}
	if(children==0)leaf[u] = true;
	if(leaf[u])wt[u]++;
	while(w){
		int v = wt[u]*(w-w/2);
		w/=2;
		if(hm[{u,p}]==1){
			one.push_back(v);
		}
		else{
			two.push_back(v);
		}
	}
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		cin >> n >> s;
		for(int i = 0; i<n-1; i++){
			int x,y,w,c;
			cin >> x >> y >> w >> c;
			adj[x].push_back({w,y});
			adj[y].push_back({w,x});
			hm[{x,y}] = c;
			hm[{y,x}] = c;
		}
		dfs(1,0,0);
		int total = 0;
		if(true){
			vector<int>dis(n+1);
			vector<bool>vis(n+1);
			queue<int>q;
			q.push(1);vis[1] = true;
			while(!q.empty()){
				int cur = q.front(); q.pop();
				for(pair<int,int>nxt: adj[cur]){
					if(!vis[nxt.second]){
						vis[nxt.second] = true;
						dis[nxt.second] = dis[cur]+nxt.first;
						q.push(nxt.second);
					}
				}
			}
			for(int i = 1; i<=n; i++){
				if(leaf[i]){
					total+=dis[i];
				}
			}
		}
		int low = -1; int high = (int)4e6; int mid = (low+high)/2;
		sort(one.begin(),one.end());
		sort(two.begin(),two.end());
		reverse(one.begin(),one.end());
		reverse(two.begin(),two.end());
		while(low+1<high){
			int mx = 0; int idx = -1; int idx2 = -1;
			int cur = 0; int cursum = 0;
			while(idx2+1<two.size()&&cur+2<=mid){
				idx2++;
				cursum+=two[idx2];
				cur+=2;
				mx = max(mx,cursum);
			}
			while(idx+1<(int)one.size()&&cur<mid){
				cur++;
				idx++;
				cursum+=one[idx];
				mx = max(cursum,mx);
			}
			while(idx2>=0){
				cursum-=two[idx2];
				idx2--;
				if(idx+1<(int)one.size()){
					idx++;
					cursum+=one[idx];
				}
				if(idx+1<(int)one.size()){
					idx++;
					cursum+=one[idx];
				}
				mx = max(cursum,mx);
			}
			if(total-mx<=s){
				high = mid;
			}
			else{
				low = mid;
			}
			mid = (low+high)/2;
		}
		cout << high << "\n";
		for(int i = 1; i<=n; i++){
			adj[i].clear();
			wt[i] = 0; leaf[i] = 0;
		}
		one.clear(); two.clear();
		hm.clear();
	}
	return 0;
}
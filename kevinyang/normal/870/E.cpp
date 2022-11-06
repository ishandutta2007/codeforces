#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = (int)1e9+7;//change this if needed
int modpow(int x, int y) {
	return !y?1:((y % 2 ? x : 1) * modpow((x * x) % mod, y / 2)) % mod;
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	map<int,vector<int>>adj;
	set<int>nodes;
	vector<pair<int,int>>arr(n);
	for(int i = 0; i<n; i++){
		int x,y;
		cin >> x >> y;
		y+=(int)2e9+5;
		arr[i] = {x,y};
		adj[x].push_back(y);
		adj[y].push_back(x);
		nodes.insert(x); nodes.insert(y);
	}
	map<int,bool>vis;
	int ans = 1;
	for(int nxt: nodes){
		if(vis[nxt])continue;
		int edges = adj[nxt].size();
		int vertices = 1;
		queue<int>q; vis[nxt] = true;
		q.push(nxt);
		while(!q.empty()){
			int cur = q.front(); q.pop();
			for(int x: adj[cur]){
				if(!vis[x]){
					vis[x] = true;
					vertices++;
					edges+=adj[x].size();
					q.push(x);
				}
			}
		}
		edges/=2;
		if(edges==vertices-1){
			int v = modpow(2,vertices)+mod-1;
			v%=mod;
			ans*=v;
			ans%=mod;
		}
		else{
			int v = modpow(2,vertices);
			ans*=v;
			ans%=mod;
		}
	}
	cout << ans << "\n";
	return 0;
}
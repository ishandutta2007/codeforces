#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = (int)1e9+7;//change this if needed
int modpow(int x, int y) {
	return !y?1:((y % 2 ? x : 1) * modpow((x * x) % mod, y / 2)) % mod;
}
int m;
int mxn = 100005;
vector<vector<pair<int,int>>>adj(mxn);
vector<int>sz(mxn);
vector<bool>vis(mxn);
vector<int>powers(mxn);
vector<int>pre(mxn);
int ans = 0;
int cent = 0;
void dfs(int u, int p){
	sz[u] = 1;
	for(pair<int,int>nxt: adj[u]){
		if(nxt.second==p||vis[nxt.second])continue;
		dfs(nxt.second,u);
		sz[u]+=sz[nxt.second];
	}
}
void getcentroid(int n, int u, int p){
	bool f = true;
	for(pair<int,int>nxt: adj[u]){
		if(nxt.second==p||vis[nxt.second])continue;
		getcentroid(n,nxt.second,u);
		if(sz[nxt.second]>n/2)f = false;
	}
	if(n-sz[u]>n/2)f = false;
	if(f)cent = u;
}
map<int,int>hm;
void dfs(int u, int p, int d, int val, int cnt){
	d%=m;
	hm[d]+=val;
	for(pair<int,int>nxt: adj[u]){
		if(nxt.second==p||vis[nxt.second])continue;
		dfs(nxt.second,u,(d+nxt.first*powers[cnt]%m)%m,val,cnt+1);
	}
}
void dfscnt(int u, int p, int d, int cnt){
	int val = m-d; val%=m;
	val*=pre[cnt]; val%=m;
	ans+=hm[val];
	for(pair<int,int>nxt: adj[u]){
		if(nxt.second==p||vis[nxt.second])continue;
		dfscnt(nxt.second,u,(d*10+nxt.first)%m,cnt+1);
	}
}
void centroid(int x){
	dfs(x,0);
	getcentroid(sz[x],x,0);
	vis[cent] = true;
	for(pair<int,int>nxt: adj[cent]){
		if(vis[nxt.second])continue;
		dfs(nxt.second,cent,nxt.first%m,1,1);
	}
	ans+=hm[0];
	hm[0]++;
	for(pair<int,int>nxt: adj[cent]){
		if(vis[nxt.second])continue;
		dfs(nxt.second,cent,nxt.first%m,-1,1);
		dfscnt(nxt.second,cent,nxt.first%m,1);
		dfs(nxt.second,cent,nxt.first%m,1,1);
	}
	for(pair<int,int>nxt: adj[cent]){
		if(vis[nxt.second])continue;
		dfs(nxt.second,cent,nxt.first,-1,1);
	}
	hm[0]--;
	for(pair<int,int>nxt: adj[cent]){
		if(vis[nxt.second])continue;
		centroid(nxt.second);
	}
}
int totient(int x){
	set<int>s;
	int ans = x;
	int k = x;
	for(int i = 2; i*i<=x; i++){
		while(k%i==0){
			k/=i;
			s.insert(i);
		}
	}
	if(k>1){
		s.insert(k);
	}
	for(int nxt: s){
		ans/=nxt;
		ans*=nxt-1;
	}
	return ans;
}

signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n >> m;
	for(int i = 0; i<n-1; i++){
		int x,y,w;
		cin >> x >> y >> w;
		x++; y++;
		adj[x].push_back({w,y});
		adj[y].push_back({w,x});
	}
	int tot = totient(m);
	mod = m;
	pre[1] = modpow(10,tot-1);
	pre[0] = 1;
	for(int i = 2; i<mxn; i++){
		pre[i] = pre[i-1]*pre[1]%mod;
	}
	powers[0] = 1;
	for(int i = 1; i<mxn;i++){
		powers[i] = powers[i-1]*10%mod;
	}
	centroid(1);
	cout << ans << "\n";
	return 0;
}
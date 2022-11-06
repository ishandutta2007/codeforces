#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
vector<vector<int>>adj(100001);
vector<int>val(100001);
int gcd(int a, int b){
	if(a==0)return b;
	if(b==0)return a;
	return gcd(b,a%b);
}
int ans = 0;
const int mod = (int)1e9+7;
void dfs(int u, int p, vector<pair<int,int>>q){
	vector<pair<int,int>>ret;
	for(pair<int,int>nxt: q){
		int d = gcd(val[u],nxt.first);
		if(ret.size()>0 && ret.back().first==d){
			ret.back().second+=nxt.second;
		}
		else{
			ret.push_back({d,nxt.second});
		}
	}
	if(ret.size()>0&&ret.back().first==val[u]){
		ret.back().second++;
	}
	else{
		ret.push_back({val[u],1});
	}
	for(pair<int,int>nxt: ret){
		ans+=nxt.first*nxt.second;
		ans%=mod;
	}
	for(int nxt: adj[u]){
		if(nxt==p)continue;
		dfs(nxt,u,ret);
	}
} 
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i<=n; i++){
		cin >> val[i];
	}
	for(int i = 0; i<n-1; i++){
		int x,y;
		cin >> x >> y;
		adj[x].push_back(y); adj[y].push_back(x);
	}
	vector<pair<int,int>>q;
	dfs(1,0,q);
	cout << ans << "\n";
	return 0;
}
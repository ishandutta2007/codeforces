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
DisjointSet ds;
int n,m;
int mxn = 4444555;
const int MM = 22;
int all = ((1<<MM)-1);
vector<bool>vis(mxn);
vector<bool>freq(mxn);
vector<int>dp(mxn);
void f(int x, int val){
	if(vis[x]){
		if(dp[x]!=0){
			ds.Union(dp[x],val);
		}
		return;
	}
	if(freq[x]){
		dp[x] = x;
		ds.Union(val,dp[x]);
	}
	vis[x] = true;
	for(int i = 0; i<MM; i++){
		if(x&(1<<i)){
			//ds.Union(x^(1<<i),val);
			f(x^(1<<i),val);
			if(dp[x^(1<<i)])dp[x] = dp[x^(1<<i)];
		}
	}
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	ds.init(mxn);
	cin >> n >> m;
	vector<int>arr(m);
	//cerr << "nae\n";
	for(int i = 0; i<m; i++){
		cin >> arr[i];
		freq[arr[i]] = true;
	}
	//cerr << "nae\n";
	set<int>s;
	for(int i = 0; i<m; i++){
		f(all^arr[i],arr[i]);
	}
	for(int i = 0; i<m; i++){
		s.insert(ds.find(arr[i]));
	}
	cout << s.size() << "\n";
	return 0;
}
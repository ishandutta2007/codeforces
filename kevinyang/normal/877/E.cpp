#include <bits/stdc++.h>
using namespace std;
#define int long long
struct SegTree{
	vector<int>arr;
	vector<int>arr2;
	vector<int>val;
	int size;
	void init(int n){
		size = 1;
		while(size<n)size*=2;
		arr.resize(size*2);
		arr2.resize(size*2);
		val.resize(size*2); 
	}
	void build(int x, int lx, int rx){
		if(rx-lx==1){
			arr2[x] = rx-lx;
			return;
		}
		int m = (lx+rx)/2;
		build(2*x+1,lx,m);
		build(2*x+2,m,rx);
		arr[x] = arr[2*x+1] + arr[2*x+2];
		arr2[x] = arr2[2*x+1] + arr2[2*x+2];
	}
	void build(){
		build(0,0,size);
	}
	void pushdown(int x, int len){
		if(val[x]==0)return;
		swap(arr[x],arr2[x]);
		if(len>1){
			val[2*x+1]^=val[x]; val[2*x+2]^=val[x];
		}
		val[x] = 0;
	}
	void set(int l, int r, int v, int x, int lx, int rx){
		if(lx>=r||l>=rx){
			pushdown(x,rx-lx);
			return;
		}
		if(lx>=l&&rx<=r){
			val[x]^=1;
			pushdown(x,rx-lx);
			return;
		}
		pushdown(x,rx-lx);
		int m = (lx+rx)/2;
		set(l,r,v,2*x+1,lx,m);
		set(l,r,v,2*x+2,m,rx);
		arr[x] = arr[2*x+1] + arr[2*x+2];
		arr2[x] = arr2[2*x+1] + arr2[2*x+2];
	}
	void set(int l, int r, int v){
		set(l,r,v,0,0,size);
	}
	int query(int l, int r, int x, int lx, int rx){
		if(lx>=r||l>=rx){
			pushdown(x,rx-lx);
			return 0;
		}
		if(lx>=l&&rx<=r){
			pushdown(x,rx-lx);
			return arr[x];
		}
		int m = (lx+rx)/2;
		pushdown(x,rx-lx);
		int s1 = query(l,r,2*x+1,lx,m);
		int s2 = query(l,r,2*x+2,m,rx);
		return s1+s2;
	}
	int query(int l, int r){
		return query(l,r,0,0,size);
	}
};
int mxn = 200005;
int n;
vector<vector<int>>adj(mxn);
vector<int>sz(mxn);
vector<int>loc(mxn);
int timer = 0;
void dfs(int u, int p){
	timer++;
	loc[u] = timer;
	sz[u] = 1;
	for(int nxt: adj[u]){
		if(nxt==p)continue;
		dfs(nxt,u);
		sz[u]+=sz[nxt];
	}
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n;
	for(int i = 2; i<=n; i++){
		int x;
		cin >> x;
		adj[i].push_back(x);
		adj[x].push_back(i);
	}
	dfs(1,0);
	SegTree segtree;
	segtree.init(mxn);
	segtree.build();
	for(int i = 1; i<=n; i++){
		int x;
		cin >> x;
		if(x==1){
			segtree.set(loc[i],loc[i]+1,0);
		}
	}
	int q;
	cin >> q;
	while(q--){
		string s;
		cin >> s;
		if(s=="get"){
			int v;
			cin >> v;
			cout << segtree.query(loc[v],loc[v]+sz[v]) << "\n";
		}
		else{
			int v;
			cin >> v;
			segtree.set(loc[v],loc[v]+sz[v],0);
		}
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
struct SegTree{
	vector<int>arr;
	vector<int>val;
	int size;
	void pushdown(int x, int len){
		if(val[x]==0)return;
		arr[x]+=val[x];
		if(len>1){
			val[2*x+1]+=val[x];
			val[2*x+2]+=val[x];
		}
		val[x] = 0;
	}
	void init(int n){
		size = 1;
		while(size<n)size*=2;
		arr.resize(size*2);
		val.resize(size*2);
	}
	void set(int l, int r, int v, int x, int lx, int rx){
		if(l>=rx||lx>=r){
			pushdown(x,rx-lx);
			return;
		}
		if(lx>=l&&rx<=r){
			val[x]+=v;
			pushdown(x,rx-lx);
			return;
		}
		pushdown(x,rx-lx);
		int m = (lx+rx)/2;
		set(l,r,v,2*x+1,lx,m);
		set(l,r,v,2*x+2,m,rx);
		arr[x] = min(arr[2*x+1],arr[2*x+2]);
	}
	void set(int l, int r, int v){
		set(l,r,v,0,0,size);
	}
	int query(int l, int r, int x, int lx, int rx){
		if(l>=rx||lx>=r){
			pushdown(x,rx-lx);
			return (int)1e18;
		}
		if(lx>=l&&rx<=r){
			pushdown(x,rx-lx);
			return arr[x];
		}
		pushdown(x,rx-lx);
		int m = (lx+rx)/2;
		int s1 = query(l,r,2*x+1,lx,m);
		int s2 = query(l,r,2*x+2,m,rx);
		return min(s1,s2);
	}
	int query(int l, int r){
		return query(l,r,0,0,size);
	}
};
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	SegTree segtree;
	segtree.init(1000005);
	vector<pair<int,pair<int,int>>>arr(n);
	for(int i = 0; i<n; i++){
		int l,r,w;
		cin >> l >> r >> w;
		arr[i] = {w,{l,r}};
	}
	sort(arr.begin(),arr.end());
	int cur = -1;
	int ans = (int)1e18;
	for(int i = 0; i<n; i++){
		while(cur<n-1&&segtree.query(1,m)==0){
			pair<int,int>p = arr[cur+1].second;
			segtree.set(p.first,p.second,1);
			cur++;
		}
		if(segtree.query(1,m)>0){
			ans = min(ans,arr[cur].first-arr[i].first);
		}
		pair<int,int>p = arr[i].second;
		segtree.set(p.first,p.second,-1);
	}
	cout << ans << "\n";
	return 0;
}
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
		arr[x] = max(arr[2*x+1],arr[2*x+2]);
	}
	void set(int l, int r, int v){
		set(l,r,v,0,0,size);
	}
	int query(int x, int lx, int rx){
		int m = (lx+rx)/2;
		pushdown(x,rx-lx);
		if(arr[x]<1)return -1;
		if(rx-lx==1)return lx;
		pushdown(2*x+2,rx-m);
		if(arr[2*x+2]>=1)return query(2*x+2,m,rx);
		return query(2*x+1,lx,m);
	}
	int query(){
		return query(0,0,size);
	}
};
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	vector<int>a(n+1);
	vector<int>b(m+1);
	for(int i = 1; i<=n; i++){
		cin >> a[i];
	}
	for(int i = 1; i<=m; i++){
		cin >> b[i];
	}
	SegTree segtree;
	segtree.init((int)1e6+5);
	for(int i = 1; i<=n; i++){
		segtree.set(1,a[i]+1,1);
	}
	for(int i = 1; i<=m; i++){
		segtree.set(1,b[i]+1,-1);
	}
	int q;
	cin >> q;
	while(q--){
		int cm;
		cin >> cm;
		if(cm==1){
			int i,v;
			cin >> i >> v;
			segtree.set(1,a[i]+1,-1);
			segtree.set(1,v+1,1);
			a[i] = v;
		}
		else{
			int i,v;
			cin >> i >> v;
			segtree.set(1,b[i]+1,1);
			segtree.set(1,v+1,-1);
			b[i] = v;
		}
		cout << segtree.query() << "\n";
	}
	return 0;
}
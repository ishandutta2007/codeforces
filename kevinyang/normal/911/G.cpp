#include <bits/stdc++.h>
using namespace std;
vector<int>a(400000);
vector<int>ans(400000);
int n,q;
struct SegTree{
	int arr[800010];
	char val[800010][101];
	bool bad[800010];
	int size;
	void init(int n){
		size = 1;
		while(size<n)size*=2;
		memset(arr,0,sizeof(arr));
		memset(val,1,sizeof(val));
		memset(bad,0,sizeof(bad));
	}
	void build(int x, int lx, int rx){
		for(int i = 1; i<=100; i++){
			val[x][i] = i;
		}
		if(rx-lx==1){
			if(lx<n){
				arr[x] = a[lx];
			}
			return;
		}
		int m = (lx+rx)/2;
		build(2*x+1,lx,m);
		build(2*x+2,m,rx);
		arr[x] = arr[2*x+1] + arr[2*x+2];
	}
	void build(){
		build(0,0,size);
	}
	void pushdown(int x, int len){
		if(!bad[x])return;
		if(len>1){
			for(int i = 1; i<=100; i++){
				val[2*x+1][i] = val[x][val[2*x+1][i]];
				val[2*x+2][i] = val[x][val[2*x+2][i]];
			}
			bad[2*x+1] = true;
			bad[2*x+2] = true;
		}
		else{
			arr[x] = val[x][arr[x]];
		}
		for(int i = 1; i<=100; i++){
			val[x][i] = i;
		}
		bad[x] = false;
	}
	void set(int l, int r, int v, int v2, int x, int lx, int rx){
		if(lx>=r||l>=rx){
			pushdown(x,rx-lx);
			return;
		}
		if(lx>=l&&rx<=r){
			for(int i = 1; i<=100; i++){
				if(val[x][i]==v)val[x][i] = v2;
			}
			bad[x] = true;
			pushdown(x,rx-lx);
			return;
		}
		pushdown(x,rx-lx);
		int m = (lx+rx)/2;
		set(l,r,v,v2,2*x+1,lx,m);
		set(l,r,v,v2,2*x+2,m,rx);
		arr[x] = arr[2*x+1] + arr[2*x+2];
	}
	void set(int l, int r, int v, int v2){
		set(l,r,v,v2,0,0,size);
	}
	void query(int x, int lx, int rx){
		if(rx-lx==1){
			pushdown(x,rx-lx);
			ans[lx] = arr[x];
			return;
		}
		int m = (lx+rx)/2;
		pushdown(x,rx-lx);
		query(2*x+1,lx,m);
		query(2*x+2,m,rx);
	}
	void query(){
		query(0,0,size);
	}
};
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n;
	for(int i = 0; i<n; i++){
		cin >> a[i];
	}
	SegTree segtree;
	segtree.init(n);
	segtree.build();
	cin >> q;
	while(q--){
		int l,r,x,y;
		cin >> l >> r >> x >> y;
		l--;
		segtree.set(l,r,x,y);
	}
	segtree.query();
	for(int i = 0; i<n; i++){
		cout << ans[i] << " ";
	}
	return 0;
}
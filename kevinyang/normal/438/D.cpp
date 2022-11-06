#include <bits/stdc++.h>
using namespace std;
#define int long long
struct SegTree{
	int size;
	vector<int>arr;
	void init(int n){
		size = 1;
		while(size<n)size*=2;
		arr.assign(2*size,0LL);
	}
	void set(int i, int v, int x, int lx, int rx){
		if(rx-lx==1){
			arr[x] = v;
			return;
		}
		int m = (lx+rx)/2;
		if(i<m){
			set(i,v,2*x+1,lx,m);
		}
		else{
			set(i,v,2*x+2,m,rx);
		}
		arr[x] = arr[2*x+1]+arr[2*x+2];
	}
	void set(int i,int v){
		set(i,v,0,0,size);
	}
	int query(int l,int r, int x, int lx, int rx){
		if(lx>=r||l>=rx)return 0;
		if(lx>=l&&rx<=r)return arr[x];
		int m = (lx+rx)/2;
		int s1 = query(l,r,2*x+1,lx,m);
		int s2 = query(l,r,2*x+2,m,rx);
		return s1+s2;
	}
	int query(int l, int r){
		return query(l,r,0,0,size);
	}
};
struct SegTree2{
	int size;
	vector<pair<int,int>>arr;
	void init(int n){
		size = 1;
		while(size<n)size*=2;
		arr.assign(2*size,make_pair(0,0));
	}
	void set(int i, int v, int x, int lx, int rx){
		if(rx-lx==1){
			arr[x] = {v,i};
			return;
		}
		int m = (lx+rx)/2;
		if(i<m){
			set(i,v,2*x+1,lx,m);
		}
		else{
			set(i,v,2*x+2,m,rx);
		}
		arr[x] = max(arr[2*x+1],arr[2*x+2]);
	}
	void set(int i,int v){
		set(i,v,0,0,size);
	}
	pair<int,int> query(int l,int r, int x, int lx, int rx){
		if(lx>=r||l>=rx)return {0,0};
		if(lx>=l&&rx<=r)return arr[x];
		int m = (lx+rx)/2;
		pair<int,int> s1 = query(l,r,2*x+1,lx,m);
		pair<int,int> s2 = query(l,r,2*x+2,m,rx);
		return max(s1,s2);
	}
	pair<int,int> query(int l, int r){
		return query(l,r,0,0,size);
	}
};
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	SegTree segtree;
	SegTree2 segtree2;
	segtree.init(n);
	segtree2.init(n);
	for(int i = 0; i<n; i++){
		int x; cin >> x;
		segtree.set(i,x);
		segtree2.set(i,x);
	}
	for(int i = 0; i<m; i++){
		int cm;
		cin >> cm;
		if(cm==1){
			int l,r;
			cin >> l >> r;
			l--; r--;
			cout << segtree.query(l,r+1) << "\n";
		}
		else if(cm==2){
			int l,r,x;
			cin >> l >> r >> x;
			l--; r--;
			while(segtree2.query(l,r+1).first>=x){
				pair<int,int>p = segtree2.query(l,r+1);
				p.first%=x;
				segtree.set(p.second,p.first);
				segtree2.set(p.second,p.first);
			}
		}
		else{
			int i,v;
			cin >> i >> v;
			i--;
			segtree.set(i,v);
			segtree2.set(i,v);
		}
	}
	return 0;
}
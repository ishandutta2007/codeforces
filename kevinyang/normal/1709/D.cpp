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
		arr[x] = max(arr[2*x+1],arr[2*x+2]);
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
		return max(s1,s2);
	}
	int query(int l, int r){
		return query(l,r,0,0,size);
	}
};
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	vector<int>arr(m+1);
	for(int i = 1; i<=m; i++){
		cin >> arr[i];
	}
	SegTree segtree;
	segtree.init(m+5);
	for(int i = 1; i<=m; i++){
		segtree.set(i,arr[i]);
	}
	int q;
	cin >> q;
	while(q--){
		int a,b,c,d,k;
		cin >> a >> b >> c >> d >> k;
		bool f = true;
		if(b>d){
			swap(b,d);
			swap(a,c);
		}
		if((d-b)%k!=0)f = false;
		if((c-a)%k!=0)f = false;
		int v = (n-a)%k;
		a = n-v;
		v = (n-c)%k;
		c = n-v;
		if(segtree.query(b,d+1)>=a)f = false;
		if(f)cout << "YES\n";
		else cout << "NO\n";	
	}
	return 0;
}
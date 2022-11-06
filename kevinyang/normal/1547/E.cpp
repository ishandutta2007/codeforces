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
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		vector<int>arr(n+1,(int)1e18);
		queue<int>q;
		for(int i = 0; i<k; i++){
			int x;
			cin >> x;
			q.push(x);
		}
		for(int i = 0; i<k; i++){
			int x;
			cin >> x;
			arr[q.front()] = x;
			q.pop();
		}
		SegTree segtree;
		segtree.init(n+1);
		for(int i = 1; i<=n; i++){
			segtree.set(i,i+1,arr[i]);
			segtree.set(i,n+1,1);
		}
		for(int i = 1; i<=n; i++){
			segtree.set(i,n+1,-1);
			segtree.set(1,i,1);
			cout << segtree.query(1,n+1) << " ";
		}
		cout << "\n";
	}
	return 0;
}
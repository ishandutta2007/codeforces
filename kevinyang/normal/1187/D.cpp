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
		arr[x] = min(arr[2*x+1],arr[2*x+2]);
	}
	void set(int i,int v){
		set(i,v,0,0,size);
	}
	int query(int l,int r, int x, int lx, int rx){
		if(lx>=r||l>=rx)return (int)1e18;
		if(lx>=l&&rx<=r)return arr[x];
		int m = (lx+rx)/2;
		int s1 = query(l,r,2*x+1,lx,m);
		int s2 = query(l,r,2*x+2,m,rx);
		return min(s1,s2);
	}
	int query(int l, int r){
		return query(l,r,0,0,size);
	}
};
struct SegTree2{
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
struct BIT{
	vector<int>arr;
	int size;
	void init(int n){
		size = n;
		arr.resize(n+5);
	}
	void update(int x, int val){
		for(int a = x; a<=size; a+=a&-a){
			arr[a]+=val;
		}
	}
	int query(int x){
		int sum = 0;
		for(int a = x; a>0; a-=a&-a){
			sum+=arr[a];
		}
		return sum;
	}
	void change(int x, int val){
		int v = query(x)-query(x-1);
		update(x,val-v);
	}
	int query(int x, int y){//inclusive
		return query(y)-query(x-1);
	}
};
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int>arr(n+1);
		vector<int>arr2(n+1);
		vector<int>arr3(n+1);
		vector<int>arr4(n+1);
		for(int i = 1; i<=n; i++){
			cin >> arr[i];
			arr3[i] = arr[i];
		}
		for(int i = 1; i<=n; i++){
			cin >> arr2[i];
			arr4[i] = arr2[i];
		}
		sort(arr3.begin(),arr3.end());
		sort(arr4.begin(),arr4.end());
		bool f = true;
		for(int i = 1; i<=n; i++){
			if(arr3[i]!=arr4[i])f = false;
		}
		if(!f){
			cout << "NO\n";
			continue;
		}
		vector<int>a(n+1);
		vector<int>b(n+1);
		vector<vector<int>>ind(n+1);
		for(int i = 1; i<=n; i++){
			ind[arr[i]].push_back(i);
		}
		if(true){
			int cur = 1;
			for(int i = 1; i<=n; i++){
				for(int nxt: ind[i]){
					a[nxt] = cur;
					cur++;
				}
			}
		}
		for(int i = 1; i<=n; i++){
			ind[i].clear();
		}
		for(int i = 1; i<=n; i++){
			ind[arr2[i]].push_back(i);
		}
		if(true){
			int cur = 1;
			for(int i = 1; i<=n; i++){
				for(int nxt: ind[i]){
					b[nxt] = cur;
					cur++;
				}
			}
		}
		SegTree segtree;
		segtree.init(n+1);
		vector<int>idx(n+1);
		vector<int>idx2(n+1);
		for(int i = 1; i<=n; i++){
			idx[a[i]] = i;
			idx2[b[i]] = i;
			segtree.set(i,a[i]);
		}
		
		for(int i = 1; i<=n; i++){
			if(segtree.query(1,idx[b[i]])<b[i])f = false;
			segtree.set(idx[b[i]],(int)1e18);
		}
		if(f)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
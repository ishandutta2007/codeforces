#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>a;
int gcd(int a, int b){
	if(a==0)return b;
	if(b==0)return a;
	return gcd(b,a%b);
}
int n;
struct SegTree{
	int size;
	vector<int>arr;
	void init(int n){
		size = 1;
		while(size<n)size*=2;
		arr.assign(2*size,0LL);
	}
	void build(int x, int lx, int rx){
		if(rx-lx==1){
			if(lx<n){
				arr[x] = a[lx];
			}
			return;
		}
		int m = (lx+rx)/2;
		build(2*x+1,lx,m);
		build(2*x+2,m,rx);
		arr[x] = gcd(arr[2*x+1],arr[2*x+2]);
	}
	void build(){
		build(0,0,size);
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
		arr[x] = gcd(arr[2*x+1],arr[2*x+2]);
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
		return gcd(s1,s2);
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
		cin >> n;
		SegTree segtree;
		segtree.init(2*n);
		a.clear();
		for(int i = 0; i<n; i++){
			int x;
			cin >> x;
			a.push_back(x);
		}
		for(int i = 0; i<n; i++){
			a.push_back(a[i]);
		}
		n*=2;
		segtree.build();
		n/=2;
		int v = segtree.query(0,n);
		int ans = 0;
		for(int i = 0; i<n; i++){
			int low = i-1; int high = i+n; int mid = (low+high)/2;
			while(low+1<high){
				if(segtree.query(i,mid+1)==v){
					high = mid;
				}
				else{
					low = mid;
				}
				mid = (low+high)/2;
			}
			ans = max(ans,high-i);
		}
		cout << ans << "\n";
	}
	return 0;
}
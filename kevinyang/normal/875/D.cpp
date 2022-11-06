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
		arr[x] = arr[2*x+1]|arr[2*x+2];
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
		return s1|s2;
	}
	int query(int l, int r){
		return query(l,r,0,0,size);
	}
};
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	SegTree segtree;
	segtree.init(n+1);
	vector<int>arr(n+1);
	for(int i = 1; i<=n; i++){
		cin >> arr[i];
		segtree.set(i,arr[i]);
	}
	set<int>bad; bad.insert(0); bad.insert(n+1);
	priority_queue<pair<int,int>>pq;
	for(int i = 1; i<=n; i++){
		pq.push({arr[i],i});
	}
	int ans = 0;
	while(pq.size()){
		pair<int,int>p = pq.top(); pq.pop();
		//cerr << p.first << " " << p.second << "\n";
		int v = 1;
		//cerr << "nae\n";
		if(true){
			int low = p.second; int high = *bad.lower_bound(p.second); int mid = (low+high)/2;
			while(low+1<high){
				if(segtree.query(p.second,mid+1)==p.first)low = mid;
				else high = mid;
				mid = (low+high)/2;
			}
			v*=(low-p.second+1);
		}
		if(true){
			int high = p.second; int low = *--bad.lower_bound(p.second); int mid = (low+high)/2;
			while(low+1<high){
				if(segtree.query(mid,p.second+1)==p.first)high = mid;
				else low = mid;
				mid = (low+high)/2;
			}
			v*=(p.second-high+1);
		}
		//cout << v << "\n";
		ans+=v-1;
		bad.insert(p.second);
	}
	cout << n*(n-1)/2-ans << "\n";
	return 0;
}
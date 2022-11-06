#include <bits/stdc++.h>
using namespace std;
#define int long long
struct SegTree{
	int size;
	vector<int>arr;
	vector<int>sums;
	void init(int n){
		size = 1;
		while(size<n)size*=2;
		arr.assign(2*size,0LL);
		sums.assign(2*size,0LL);
	}
	void set(int l, int r, int v, int x, int lx, int rx){
		if(lx>=r||l>=rx)return;
		if(lx>=l&&rx<=r){
			arr[x]+=v;
			sums[x]+=v;
			return;
		}
		int m = (lx+rx)/2;
		set(l,r,v,2*x+1,lx,m);
		set(l,r,v,2*x+2,m,rx);
		sums[x] = min(sums[2*x+1],sums[2*x+2])+arr[x];
	}
	void set(int l, int r, int v){
		set(l,r,v,0,0,size);
	}
	int query(int l, int r, int x, int lx, int rx){
		if(lx>=r||l>=rx)return (int)1e18;
		if(lx>=l&&rx<=r){
			return sums[x];
		}
		int m = (lx+rx)/2;
		int s1 = query(l,r,2*x+1,lx,m);
		int s2 = query(l,r,2*x+2,m,rx);
		return min(s1,s2)+arr[x];
	}
	int query(int l, int r){
		return query(l,r,0,0,size);
	}
};
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int>arr(n+1);
	SegTree segtree;
	segtree.init(n+1);
	for(int i = 1; i<=n; i++){
		cin >> arr[i];
	}
	int ans = 0;
	priority_queue<pair<int,int>>pq;
	for(int i = 1; i<=n; i++){
		if(arr[i]>=0){
			ans++;
			segtree.set(i,n+1,arr[i]);
		}
		else{
			pq.push({arr[i],i});
		}
	}
	while(!pq.empty()){
		pair<int,int>p = pq.top();
		pq.pop();
		if(segtree.query(p.second,n+1)>=abs(p.first)){
			ans++;
			segtree.set(p.second,n+1,p.first);
		}
	}
	cout << ans << "\n";
	return 0;
}
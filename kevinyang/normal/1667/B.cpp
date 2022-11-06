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
		if(lx>=r||l>=rx)return -(int)1e18;
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
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int>arr(n+1);
		for(int i = 1; i<=n; i++){
			cin >> arr[i];
		}
		vector<int>psa(n+1);
		for(int i = 1; i<=n; i++){
			psa[i] = psa[i-1]+arr[i];
		}
		vector<pair<int,int>>vals(n+1);
		vector<int>idx(n+1);
		vals[0] = {0,0};
		for(int i = 1; i<=n; i++){
			vals[i] = {psa[i],i};
		}
		sort(vals.begin(),vals.end());
		for(int i = 0; i<=n; i++){
			idx[vals[i].second] = i;
		}
		SegTree segtree;
		segtree.init(n+5);
		SegTree segtree2;
		segtree2.init(n+5);
		SegTree segtree3;
		segtree3.init(n+5);
		for(int i = 0; i<=n+4; i++){
			segtree.set(i,-(int)1e18);
			segtree2.set(i,-(int)1e18);
			segtree3.set(i,-(int)1e18);
		}
		segtree.set(idx[0],0);
		segtree2.set(idx[0],0);
		segtree3.set(idx[0],0);
		for(int i = 1; i<=n; i++){
			int ind = idx[i];
			pair<int,int>p = make_pair(vals[ind].first+1,0);
			int r = lower_bound(vals.begin(),vals.end(),p)-vals.begin();
			p = make_pair(vals[ind].first,0);
			int l = --lower_bound(vals.begin(),vals.end(),p)-vals.begin();
			int v = max(segtree.query(0,l+1)+i,segtree2.query(r,n+5)-i);
			if(l+1<r){
				v = max(v,segtree3.query(l+1,r));
			}
			segtree.set(ind,v-i);
			segtree2.set(ind,v+i);
			segtree3.set(ind,v);
		}
		int ind = idx[n];
		int v1 = segtree.query(ind,ind+1)+n;
		int v2 = segtree2.query(ind,ind+1)-n;
		/*
		for(int i = 0; i<=n; i++){
			cout << segtree.query(i,i+1) << " ";
		}
		cout << "\n";
		for(int i = 0; i<=n; i++){
			cout << segtree2.query(i,i+1) << " ";
		}
		cout << "\n";
		*/
		cout << max(v1,v2) << "\n";
	}
	return 0;
}
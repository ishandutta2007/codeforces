#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = (int)1e9+7;//change this if needed
int modpow(int x, int y) {
	return !y?1:((y % 2 ? x : 1) * modpow((x * x) % mod, y / 2)) % mod;
}
struct SegTree{
	int size;
	vector<int>arr;
	void init(int n){
		size = 1;
		while(size<n)size*=2;
		arr.assign(2*size,1LL);
	}
	void set(int i, int v, int x, int lx, int rx){
		if(rx-lx==1){
			arr[x] *= v;
			arr[x]%=mod;
			return;
		}
		int m = (lx+rx)/2;
		if(i<m){
			set(i,v,2*x+1,lx,m);
		}
		else{
			set(i,v,2*x+2,m,rx);
		}
		arr[x] = arr[2*x+1]*arr[2*x+2];
		arr[x]%=mod;
	}
	void set(int i,int v){
		set(i,v,0,0,size);
	}
	int query(int l,int r, int x, int lx, int rx){
		if(lx>=r||l>=rx)return 1;
		if(lx>=l&&rx<=r)return arr[x];
		int m = (lx+rx)/2;
		int s1 = query(l,r,2*x+1,lx,m);
		int s2 = query(l,r,2*x+2,m,rx);
		return s1*s2%mod;
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
	for(int i = 1; i<=n; i++){
		cin >> arr[i];
	}
	vector<int>factor(1000005,(int)1e18);
	for(int i = 2; i<=1000000; i++){
		for(int j = i; j<=1000000; j+=i){
			factor[j] = min(factor[j],i);
		}
	}
	vector<int>inv(1000005);
	for(int i = 1; i<=1000000; i++){
		inv[i] = modpow(i,mod-2);
	}
	vector<vector<int>>ind(1000005);
	for(int i = 1; i<=n; i++){
		set<int>s;
		int k = arr[i];
		while(k!=1){
			s.insert(factor[k]);
			k/=factor[k];
		}
		for(int nxt: s){
			ind[nxt].push_back(i);
		}
	}
	SegTree segtree;
	segtree.init(n+1);
	for(int i = 1; i<=n; i++){
		segtree.set(i,arr[i]);
	}
	for(int i = 1; i<=1000000; i++){
		if(ind[i].size()){
			int idx = ind[i][0];
			segtree.set(idx,inv[i]);
			segtree.set(idx,i-1);
		}
	}
	int q;
	cin >> q;
	vector<pair<int,int>>queries(q);
	vector<pair<int,int>>old(q);
	map<pair<int,int>,int>hm;
	for(int i = 0; i<q; i++){
		int x,y;
		cin >> x >> y;
		queries[i] = {x,y};
		old[i] = {x,y};
	}
	int cur = 0;
	sort(queries.begin(),queries.end());
	for(int i = 1; i<=n; i++){
		while(cur<q&&queries[cur].first==i){
			hm[queries[cur]] = segtree.query(queries[cur].first,queries[cur].second+1);
			cur++;
		}
		set<int>s;
		int k = arr[i];
		while(k!=1){
			s.insert(factor[k]);
			k/=factor[k];
		}
		for(int nxt: s){
			auto it = upper_bound(ind[nxt].begin(),ind[nxt].end(),i);
			if(it==ind[nxt].end())continue;
			segtree.set(*it,inv[nxt]);
			segtree.set(*it,nxt-1);
		}
	}
	for(int i = 0; i<q; i++){
		cout << hm[old[i]] << "\n";
	}
	return 0;
}
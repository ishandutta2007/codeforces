#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>>a(200000,vector<int>(10));
vector<int>val(200000);
int n,m;
struct SegTree{
	int size;
	vector<int>arr;
	vector<int>arr2;
	void init(int n){
		size = 1;
		while(size<n)size*=2;
		arr.assign(size*2,(int)1e18);
		arr2.assign(size*2,(int)1e18);
	}
	void build(int x, int lx, int rx, int j){
		if(rx-lx==1){
			if(lx<n){
				if(a[lx][j]==0){
					arr[x] = (int)1e18;
				}
				else{
					arr[x] = val[lx];
				}
			}
			return;
		}
		int m = (lx+rx)/2;
		build(2*x+1,lx,m,j);
		build(2*x+2,m,rx,j);
		arr2[x] = min({arr2[2*x+1],arr2[2*x+2],arr[2*x+1]+arr[2*x+2]});
		arr[x] = min({arr[2*x+1],arr[2*x+2]});
	}
	void build(int j){
		build(0,0,size,j);
	}
	void set(int i, int v, int x, int lx, int rx){
		if(rx-lx==1){
			if(v==0)arr[x] = (int)1e18;
			else arr[x] = val[i];
			return;
		}
		int m = (lx+rx)/2;
		if(i<m){
			set(i,v,2*x+1,lx,m);
		}
		else{
			set(i,v,2*x+2,m,rx);
		}
		arr2[x] = min({arr2[2*x+1],arr2[2*x+2],arr[2*x+1]+arr[2*x+2]});
		arr[x] = min({arr[2*x+1],arr[2*x+2]});
	}
	void set(int i,int v){
		set(i,v,0,0,size);
	}
	pair<int,int> query(int l,int r, int x, int lx, int rx){
		if(lx>=r||l>=rx)return make_pair((int)1e18,(int)1e18);
		if(lx>=l&&rx<=r)return {arr[x],arr2[x]};
		int m = (lx+rx)/2;
		pair<int,int>ret;
		pair<int,int> s1 = query(l,r,2*x+1,lx,m);
		pair<int,int> s2 = query(l,r,2*x+2,m,rx);
		ret.second = min({s1.second,s2.second,s1.first+s2.first});
		ret.first = min(s1.first,s2.first);
		return ret;
	}
	pair<int,int> query(int l, int r){
		return query(l,r,0,0,size);
	}
};
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 0; i<n; i++){
		cin >> val[i];
		int cur = val[i];
		for(int j = 0; j<10; j++){
			a[i][j] = cur%10;
			cur/=10;
		}
	}
	vector<SegTree>segtree(10);
	for(int j = 0; j<10; j++){
		segtree[j].init(n);
		segtree[j].build(j);
	}
	while(m--){
		int cm;
		cin >> cm;
		if(cm==1){
			int i,x;
			cin >> i >> x;
			i--;
			val[i] = x;
			int cur = x;
			for(int j = 0; j<10; j++){
				a[i][j] = cur%10;
				cur/=10;
				segtree[j].set(i,a[i][j]);
			}
		}
		else{
			int l,r;
			cin >> l >> r;
			l--; r--;
			int ans = (int)1e18;
			for(int j = 0; j<10; j++){
				pair<int,int>p = segtree[j].query(l,r+1);
				ans = min(ans,p.second);
			}
			if(ans==(int)1e18)cout << "-1\n";
			else cout << ans << "\n";
		}
	}
	return 0;
}
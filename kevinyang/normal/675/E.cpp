#include <bits/stdc++.h>
using namespace std;
#define int long long
struct SegTree{
	int size;
	vector<pair<int,int>>arr;
	void init(int n){
		size = 1;
		while(size<n)size*=2;
		arr.resize(size*2);
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
	int n;
	cin >> n;
	vector<int>arr(n+1);
	for(int i = 1; i<n; i++){
		cin >> arr[i];
	}
	SegTree segtree;
	segtree.init(n+1);
	for(int i = 1; i<n; i++){
		segtree.set(i,arr[i]);
	}
	segtree.set(n,0);
	vector<int>dp(n+1);
	int ans = 0;
	for(int i = n-1; i>=1; i--){
		auto p = segtree.query(i+1,arr[i]+1);
		dp[i] = dp[p.second]+n-i-arr[i]+p.second;
		ans+=dp[i];
		//cout << ans << " ";
	}
	cout << ans << "\n";
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
struct SegTree{
	int size;
	vector<int>arr;
	vector<int>val;
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
		arr[x] = max(arr[2*x+1],arr[2*x+2]);
	}
	void set(int l, int r, int v){
		set(l,r,v,0,0,size);
	}
	int query(int l, int r, int x, int lx, int rx){
		if(l>=rx||lx>=r){
			pushdown(x,rx-lx);
			return 0;
		}
		if(lx>=l&&rx<=r){
			pushdown(x,rx-lx);
			return arr[x];
		}
		pushdown(x,rx-lx);
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
	int n,k;
	cin >> n >> k;
	vector<SegTree>dp(k+1);
	for(int i = 1; i<=k; i++){
		dp[i].init(n+3);
		dp[i].set(1,n+1,1);
	}
	vector<vector<int>>indices(n+1);
	for(int i = 1; i<=n; i++){
		indices[i].push_back(0);
	}
	vector<int>arr(n+1);
	for(int i = 1; i<=n; i++){
		cin >> arr[i];
		indices[arr[i]].push_back(i);
	}
	for(int i = 2; i<=n; i++){
		int recent = *--lower_bound(indices[arr[i]].begin(),indices[arr[i]].end(),i);
		//cerr << recent << "\n";
		recent++;
		for(int j = 2; j<=k; j++){
			int v = dp[j-1].query(1,i)+1;
			int old = dp[j].query(i,i+1);
			v = max(v,old);
			dp[j].set(i,i+1,v-old);
		}
		for(int j = 1; j<=k; j++){
			dp[j].set(recent,i,1);
		}
		
		//cerr << "nae\n";
	}
	//cerr << "nae2\n";
	cout << dp[k].query(1,n+1) << "\n";
	return 0;
}
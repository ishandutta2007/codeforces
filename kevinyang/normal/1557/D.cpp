#include <bits/stdc++.h>
using namespace std;
#define int long long
struct SegTree{
	vector<pair<int,int>>arr;
	vector<pair<int,int>>val;
	int size;
	void init(int n){
		size = 1;
		while(size<n)size*=2;
		arr.resize(size*2);
		val.resize(size*2);
	}
	void pushdown(int x, int len){
		if(val[x].first==0)return;
		arr[x] = max(arr[x],val[x]);
		if(len>1){
			val[2*x+1] = max(val[x],val[2*x+1]);
			val[2*x+2] = max(val[x],val[2*x+2]);
		}
		val[x] = {0,0};
	}
	void set(int l, int r, pair<int,int> v, int x, int lx, int rx){
		if(lx>=r||l>=rx){
			pushdown(x,rx-lx);
			return;
		}
		if(lx>=l&&rx<=r){
			val[x] = max(val[x],v);
			pushdown(x,rx-lx);
			return;
		}
		int m = (lx+rx)/2;
		pushdown(x,rx-lx);
		set(l,r,v,2*x+1,lx,m);
		set(l,r,v,2*x+2,m,rx);
		arr[x] = max(arr[2*x+1],arr[2*x+2]);
	}
	void set(int l, int r, pair<int,int> v){
		set(l,r,v,0,0,size);
	}
	pair<int,int> query(int l, int r, int x, int lx, int rx){
		if(lx>=r||l>=rx){
			pushdown(x,rx-lx);
			return {0,0};
		}
		if(lx>=l&&rx<=r){
			pushdown(x,rx-lx);
			return arr[x];
		}
		int m = (lx+rx)/2;
		pushdown(x,rx-lx);
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
	int n,m;
	cin >> n >> m;
	vector<int>sorted; sorted.push_back(0);
	vector<int>idx(m);
	vector<pair<int,int>>arr(m);
	for(int i = 0; i<m; i++){
		cin >> idx[i] >> arr[i].first >> arr[i].second;
		sorted.push_back(arr[i].first);
		sorted.push_back(arr[i].second);
	}
	vector<vector<pair<int,int>>>ranges(n+1);
	SegTree segtree;
	segtree.init(600005);
	vector<int>dp(n+1);
	sort(sorted.begin(),sorted.end());
	for(int i = 0; i<m; i++){
		arr[i].first = lower_bound(sorted.begin(),sorted.end(),arr[i].first)-sorted.begin();
		arr[i].second = lower_bound(sorted.begin(),sorted.end(),arr[i].second) - sorted.begin();
		ranges[idx[i]].push_back({arr[i].first,arr[i].second});
	}
	pair<int,int>ans = {0,0};
	for(int i = 1; i<=n; i++){
		pair<int,int> v = {0,0};
		for(auto nxt: ranges[i]){
			v = max(v,segtree.query(nxt.first,nxt.second+1));
		}
		dp[i] = v.second;
		v.first++; v.second = i;
		for(auto nxt: ranges[i]){
			segtree.set(nxt.first,nxt.second+1,v);
		}
		ans = max(ans,v);
	}
	cout << n-ans.first << "\n";
	set<int>s;
	int cur = ans.second;
	while(cur!=0){
		s.insert(cur);
		cur = dp[cur];
	}
	for(int i = 1; i<=n; i++){
		if(s.find(i)==s.end())cout << i << " ";
	}
	cout << "\n";
	return 0;
}
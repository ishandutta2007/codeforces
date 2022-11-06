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
bool comp(pair<int,int>a, pair<int,int>b){
	return a.second < b.second;
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int>arr(n+1);
	for(int i = 1; i<=n; i++){
		cin >> arr[i];
	}
	if(true){
		int sum = 0;
		for(int i = 1; i<=n; i++){
			sum+=arr[i];
		}
		if(sum==n){
			cout << "1\n";
			return 0;
		}
	}
	vector<vector<int>>ind(100005);
	for(int i = 1; i<=n; i++){
		ind[arr[i]].push_back(i);
	}
	vector<pair<int,int>>queries;
	for(int i = 2; i<=n; i++){
		vector<int>inds;
		inds.push_back(0);
		for(int nxt: ind[i]){
			inds.push_back(nxt);
		}
		inds.push_back(n+1);
		for(int j = 0; j<inds.size()-1; j++){
			if(inds[j]+1==inds[j+1])continue;
			queries.push_back({inds[j]+1,inds[j+1]});
		}
	}
	SegTree segtree;
	segtree.init(100005);
	for(int i = 1; i<100005; i++){
		segtree.set(i,-1);
	}
	map<pair<int,int>,int>hm;
	int cur = 0;
	sort(queries.begin(),queries.end(),comp);
	for(int i = 1; i<=n; i++){
		segtree.set(arr[i],i);
		//cout << segtree.query(1,2) << "\n";
		while(cur<queries.size()&&queries[cur].second==i+1){
			//cout << queries[cur].first << " " << queries[cur].second << " ";
			int low = 0; int high = 100004; int mid = (low+high)/2;
			while(low+1<high){
				if(segtree.query(1,mid+1)<queries[cur].first){
					high = mid;
				}
				else{
					low = mid;
				}
				mid = (low+high)/2;
			}
			//cout << high << "\n";
			hm[queries[cur]] = high;
			cur++;
		}
	}
	//cout << hm[{4,6}] << "\n";
	for(int i = 2; i<=n; i++){
		vector<int>inds;
		inds.push_back(0);
		for(int nxt: ind[i]){
			inds.push_back(nxt);
		}
		bool f = false;
		inds.push_back(n+1);
		for(int j = 0; j<inds.size()-1; j++){
			if(inds[j]+1==inds[j+1])continue;
			if(hm[{inds[j]+1,inds[j+1]}]==i)f = true;
		}
		if(!f){
			cout << i << "\n";
			return 0;
		}
	}
	set<int>s;
	for(int i = 1; i<=n; i++){
		s.insert(arr[i]);
	}
	bool f = true;
	for(int i = 1; i<=n; i++){
		if(s.find(i)==s.end())f = false;
	}
	
	if(!f)cout << n+1 << "\n";
	else cout << n+2 << "\n";
	return 0;
}
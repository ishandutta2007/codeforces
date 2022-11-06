#include <bits/stdc++.h>
using namespace std;
#define int long long
struct DisjointSet{
	vector<int>parent,sz,mn,mx;
	int size;
	void init(int n){
		size = n;
		parent.resize(n+1); sz.resize(n+1); mn.resize(n+1); mx.resize(n+1);
		for(int i = 1; i<=n; i++){
			parent[i] = i;
			sz[i] = 1;
			mn[i] = mx[i] = i;
		}
	}
	int find(int x){
		if(parent[x]==x)return x;
		return find(parent[x]);
	}
	void Union(int x, int y){
		x = find(x); y = find(y);
		if(x==y)return;
		if(sz[x]<sz[y]){
			parent[x] = y;
			sz[y]+=sz[x];
			mn[y] = min(mn[y],mn[x]);
			mx[y] = max(mx[y],mx[x]);
		}
		else{
			parent[y] = x;
			sz[x]+=sz[y];
			mn[x] = min(mn[x],mn[y]);
			mx[x] = max(mx[x],mx[y]);
		}
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
	DisjointSet ds;
	ds.init(n);
	bool f = true;
	for(int i = 1; i<n; i++){
		if(arr[i]==arr[i+1]){
			ds.Union(i,i+1);
		}
	}
	set<pair<int,int>>s;
	for(int i = 1; i<=n; i++){
		if(ds.find(i)==i){
			s.insert({arr[i],i});
			//cerr << arr[i] << " " << i << "\n";
		}
	}
	while(s.size()>=2){
		pair<int,int>p = *s.begin();
		s.erase(p);
		int low = ds.mn[p.second]; int high = ds.mx[p.second];
		if((high-low+1)%2==1)f = false;
		if(low==1){
			int v = arr[high+1];
			s.erase({v,ds.find(high+1)});
			ds.Union(p.second,high+1);
			s.insert({v,ds.find(low)});
		}
		else if(high==n){
			int v = arr[low-1];
			s.erase({v,ds.find(low-1)});
			ds.Union(p.second,low-1);
			s.insert({v,ds.find(low)});
		}
		else if(arr[high+1]>arr[low-1]){
			int v = arr[low-1];
			s.erase({v,ds.find(low-1)});
			ds.Union(p.second,low-1);
			s.insert({v,ds.find(low)});
		}
		else if(arr[high+1]<arr[low-1]){
			int v = arr[high+1];
			s.erase({v,ds.find(high+1)});
			ds.Union(p.second,high+1);
			s.insert({v,ds.find(low)});
		}
		else if(arr[high+1]==arr[low-1]){
			int v = arr[high+1];
			s.erase({v,ds.find(high+1)});
			s.erase({v,ds.find(low-1)});
			ds.Union(low-1,low);
			ds.Union(low,high+1);
			s.insert({v,ds.find(low)});
		}
	}
	if(f){
		cout << "YES\n";
	}
	else{
		cout << "NO\n";
	}
	return 0;
}
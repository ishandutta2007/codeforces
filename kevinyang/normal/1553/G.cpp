#include <bits/stdc++.h>
using namespace std;
#define int long long
struct DisjointSet{
	vector<int>parent,sz;
	int size;
	void init(int n){
		size = n;
		parent.resize(n+1); sz.resize(n+1);
		for(int i = 1; i<=n; i++){
			parent[i] = i;
			sz[i] = 1;
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
		}
		else{
			parent[y] = x;
			sz[x]+=sz[y];
		}
	}
};
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,q;
	cin >> n >> q;
	vector<int>arr(n+1);
	for(int i = 1; i<=n; i++){
		cin >> arr[i];
	}
	DisjointSet ds;
	ds.init(1000005);
	vector<int>factor(1000005,(int)1e9);
	for(int i = 2; i<=1000001; i++){
		for(int j = i; j<=1000001; j+=i){
			factor[j] = min(factor[j],i);
		}
	}
	for(int i = 1; i<=n; i++){
		set<int>s;
		int k = arr[i];
		while(k!=1){
			s.insert(factor[k]);
			k/=factor[k];
			//cerr << k << " ";
		}
		for(int nxt: s){
			ds.Union(arr[i],nxt);
		}
	}
	cerr << "nae\n";
	set<pair<int,int>>edges;
	for(int i = 1; i<=n; i++){
		int v = arr[i];
		set<int>s;
		int k = v+1;
		while(k!=1){
			s.insert(factor[k]);
			k/=factor[k];
		}
		vector<int>primes;
		for(int nxt: s){
			primes.push_back(ds.find(nxt));
		}
		primes.push_back(ds.find(v));
		for(int i = 0; i<primes.size(); i++){
			for(int j = i+1; j<primes.size(); j++){
				edges.insert({min(primes[i],primes[j]),max(primes[i],primes[j])});
			}
		}
	}
	while(q--){
		int x,y;
		cin >> x >> y;
		x = arr[x]; y = arr[y];
		int x1 = ds.find(x); int y1 = ds.find(y);
		if(x1==y1){
			cout << "0\n";
			continue;
		}
		bool f = false;
		if(true){
			set<int>s;
			int k = x+1;
			while(k!=1){
				s.insert(factor[k]);
				k/=factor[k];
			}
			for(int nxt: s){
				if(ds.find(nxt)==y1)f = true;
			}
		}
		if(true){
			set<int>s;
			int k = y+1;
			while(k!=1){
				s.insert(factor[k]);
				k/=factor[k];
			}
			for(int nxt: s){
				if(ds.find(nxt)==x1)f = true;
			}
		}
		if(f||edges.find({x1,y1})!=edges.end()||edges.find({y1,x1})!=edges.end()){
			cout << "1\n";
		}
		else{
			cout << "2\n";
		}
	}
	return 0;
}
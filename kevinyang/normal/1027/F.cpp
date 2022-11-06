#include <bits/stdc++.h>
using namespace std;
//#define int long long
struct DisjointSet{
	vector<int>rank, parent, sz, sz2;
	int size;
	void init(int n){
		size = n;
		rank.resize(n+1); sz.resize(n+1); parent.resize(n+1); sz2.resize(n+1);
		for(int i = 1; i<=n; i++){
			parent[i] = i; sz[i] = 1;
		}
	}
	int find(int x){
		return parent[x]==x?x:find(parent[x]);
	}
	void Union(int x, int y){
		x = find(x); y = find(y);
		if(x==y)return;
		if(rank[x]==rank[y])rank[x]++;
		if(rank[x]<rank[y]){
			parent[x] = y;
			sz[y]+=sz[x];
			sz2[y]+=sz2[x]; sz2[y]++;
		}
		else{
			parent[y] = x;
			sz[x]+=sz[y];
			sz2[x]+=sz2[y]; sz2[x]++;
		}
	}
	int getsz(int x){
		return sz[find(x)];
	}
	int getsz2(int x){
		return sz2[find(x)];
	}
	void setsz2(int x){
		sz2[find(x)]++;
	}
};
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int>sorted; sorted.push_back(0);
	vector<pair<int,int>>edges(n);
	for(int i = 0; i<n; i++){
		int x,y;
		cin >> x >> y;
		sorted.push_back(x); sorted.push_back(y);
		edges[i] = {x,y};
	}
	sort(sorted.begin(),sorted.end());
	int low = 0; 
	for(int i = 0; i<n; i++){
		edges[i].first = lower_bound(sorted.begin(),sorted.end(),edges[i].first) - sorted.begin();
		edges[i].second = lower_bound(sorted.begin(),sorted.end(),edges[i].second) - sorted.begin();
		low = max(edges[i].first,low);
	}
	low--;
	int high = 2*n+5; int mid = (low+high)/2;
	while(low+1<high){
		DisjointSet ds;
		ds.init(mid);
		for(pair<int,int>p: edges){
			if(p.second>mid){
				ds.setsz2(p.first);
				continue;
			}
			if(ds.find(p.first)==ds.find(p.second)){
				ds.setsz2(p.first);
			}
			else{
				ds.Union(p.first,p.second);
			}
		}
		//cerr << mid << "\n";
		bool f = true;
		for(int i = 1; i<=mid; i++){
			if(ds.getsz(i)<ds.getsz2(i))f = false;
			//cerr << i << " " << ds.getsz(i) << " " << ds.getsz2(i) << "\n";
		}
		//cerr << mid << "\n";
		if(f)high = mid;
		else low = mid;
		mid = (low+high)/2;
	}
	if(high==2*n+5){
		cout << "-1\n";
		return 0;
	}
	cout << sorted[high] << "\n";
	return 0;
}
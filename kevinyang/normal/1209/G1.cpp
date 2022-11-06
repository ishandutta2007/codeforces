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
	vector<int>fst(200001);
	vector<int>lst(200001);
	DisjointSet ds;
	ds.init(200000);
	set<int>s;
	for(int i = 1; i<=n; i++){
		if(fst[arr[i]]==0)fst[arr[i]] = i;
	}
	for(int i = n; i>=1; i--){
		if(lst[arr[i]]==0)lst[arr[i]] = i;
	}
	vector<int>ends;
	for(int i = 1; i<=n; i++){
		if(fst[arr[i]]==i){
			s.insert(arr[i]);
		}
		if(lst[arr[i]]==i){
			s.erase(arr[i]);
		}
		if(s.size()==0){
			ends.push_back(i);
		}
	}
	int ans = 0;
	int start = 1;
	for(int nxt: ends){
		map<int,int>freq;
		int mx = 0;
		for(int i = start; i<=nxt; i++){
			freq[arr[i]]++;
			mx = max(mx,freq[arr[i]]);
		}
		ans+=(nxt-start+1)-mx;
		start = nxt+1;
		//cout << nxt << "\n";
	}
	cout << ans << "\n";
	return 0;
}
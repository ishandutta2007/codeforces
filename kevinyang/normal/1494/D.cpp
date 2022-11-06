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
		return parent[x] = find(parent[x]);
	}
	void Union(int x, int y){
		x = find(x); y = find(y);
		if(x==y)return;
		parent[x] = y;
	}
};
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<vector<int>>arr(n+1,vector<int>(n+1));
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=n; j++){
			cin >> arr[i][j];
		}
	}
	vector<vector<pair<int,int>>>pairs(5001);
	DisjointSet ds;
	ds.init(1001);
	for(int i = 1; i<=n; i++){
		for(int j = i+1; j<=n; j++){
			pairs[arr[i][j]].push_back({i,j});
		}
	}
	int curlast = n+1;
	vector<int>cost(1001);
	vector<pair<int,int>>ans;
	for(int t = 1; t<=5000; t++){
		DisjointSet ds2;
		ds2.init(1001);
		set<int>s;
		for(pair<int,int>nxt: pairs[t]){
			s.insert(ds.find(nxt.first));
			s.insert(ds.find(nxt.second));
			ds2.Union(ds.find(nxt.first),ds.find(nxt.second));
		}
		vector<vector<int>>nodes(1001);
		set<int>s2;
		for(int nxt: s){
			s2.insert(ds2.find(nxt));
			nodes[ds2.find(nxt)].push_back(nxt);
		}
		for(int cur: s2){
			for(int nxt: nodes[cur]){
				ans.push_back({nxt,curlast});
				ds.Union(nxt,curlast);
			}
			cost[curlast] = t;
			curlast++;
		}
	}
	for(int i = 1; i<=n; i++){
		cost[i] = arr[i][i];
	}
	cout << curlast-1 << "\n";
	for(int i = 1; i<curlast; i++){
		cout << cost[i] << " ";
	}
	cout << "\n";
	cout << ds.find(1) << "\n";
	for(pair<int,int>nxt: ans){
		cout << nxt.first << " " << nxt.second << "\n";
	}
	return 0;
}
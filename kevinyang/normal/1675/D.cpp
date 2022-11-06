#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mxn = 200005;
vector<vector<int>>adj(mxn);
vector<vector<int>>val(mxn);
set<int>s;
void reset(int n){
	for(int i = 1; i<=n; i++){
		adj[i].clear();
		val[i].clear();
	}
	s.clear();
}
void dfs(int u, int p, int d){
	if(s.find(d)!=s.end())s.erase(d);
	val[d].push_back(u);
	vector<int>c;
	for(int nxt: adj[u]){
		if(nxt==p)continue;
		c.push_back(nxt);
	}
	if(c.size())dfs(c[0],u,d);
	for(int i = 1; i<c.size(); i++){
		dfs(c[i],u,*s.begin());
	}
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int root = 0;
		for(int i = 1; i<=n; i++){
			s.insert(i);
		}
		for(int i = 1; i<=n; i++){
			int x;
			cin >> x;
			//cout << i << " " << x << "\n";
			if(x==i)root = x;
			if(x==i)continue;
			adj[i].push_back(x);
			adj[x].push_back(i);
		}
		s.erase(1);
		dfs(root,0,1);
		int sz = 0;
		for(int i = 1; i<=n; i++){
			if(val[i].size())sz = i;
		}
		cout << sz << "\n";
		for(int i = 1; i<=sz; i++){
			cout << val[i].size() << "\n";
			for(int nxt: val[i]){
				cout << nxt << " ";
			}
			cout << "\n";
		}
		reset(n);
	}
	return 0;
}
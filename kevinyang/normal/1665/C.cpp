#include <bits/stdc++.h>
using namespace std;
#define int long long
int mxn = 200005;
vector<int>dis(mxn);
vector<int>vals;
vector<vector<int>>adj(mxn);
void dfs(int u, int p){
	int children = 0;
	for(int nxt: adj[u]){
		if(nxt==p)continue;
		children++;
		dfs(nxt,u);
	}
	if(children){
		vals.push_back(children);
	}
}
void reset(int n){
	for(int i = 1; i<=n; i++){
		dis[i] = 0;
		adj[i].clear();
	}
	vals.clear();
}
bool check(int x){
	vector<int>a;
	a.push_back(0);
	for(int nxt: vals){
		a.push_back(nxt);
	}
	int extra = x-vals.size();
	for(int i = 1; i<a.size(); i++){
		a[i]-=extra+i;
	}
	int sum = 0;
	for(int i = 1; i<a.size(); i++){
		sum+=max(0LL,a[i]);
	}
	if(sum<=extra){
		return true;
	}
	return false;
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		for(int i = 2; i<=n; i++){
			int x;
			cin >> x;
			adj[i].push_back(x);
			adj[x].push_back(i);
		}
		dfs(1,0);
		vals.push_back(1);
		int cur = vals.size();
		sort(vals.begin(),vals.end());
		//cout << "\n";
		int low = vals.size()-1; int high = n+1; int mid = (low+high)/2;
		while(low+1<high){
			if(check(mid)){
				high = mid;
			}
			else{
				low = mid;
			}
			mid = (low+high)/2;
		}
		cout << high << "\n";
		reset(n);
	}
	return 0;
}
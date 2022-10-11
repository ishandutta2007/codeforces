#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
vector<int> g[110], ans;
ll n, a[110];

void dfs(int v){
	int u;
	ans.pb(v);
	for(int i = 0; i < g[v].size(); i++){
		u = g[v][i];
		dfs(u);
	}
}

int main(){
	cin >> n;
	for(ll i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(a[i] * 2 == a[j] || a[i] == a[j] * 3){
				g[i].pb(j);
			}
		}
	}
	for(int i = 0; i < n; i++){
		ans.clear();
		dfs(i);
		if(ans.size() == n){
			for(int j = 0; j < n; j++){
				cout << a[ans[j]] << ' ';
			}
			return 0;
		}
	}
	return 0;
}
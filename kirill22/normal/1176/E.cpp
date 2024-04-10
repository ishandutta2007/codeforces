#include <bits/stdc++.h>
using namespace std;
#define int long long
int h;
vector<pair<int,int> > a;
vector<vector<int>> g;
int dfs (int v) {
	if (v == a[v].first)
		return v;
    a[v].first=dfs(a[v].first);
	return a[v].first;
}
void make(int v,int k){
    int i=dfs(v);
    int g=dfs(k);
    if (g!=i){
        h--;
        a[i].first=g;

    }

}
vector<int> ans;
vector<int> used;
void dfs(int v,int color){
	used[v] = color;
	for(auto x : g[v]){
		if(used[x] == 0){
			dfs(x, 3 - color);
		}
	}
}
void solve(){
	ans.clear();
	g.clear();
	a.clear();
	used.clear();
	int n, m;
	cin >> n >> m;
    h=n-1;
    g.resize(n);
    used.resize(n, 0);
    for(int i = 0;i < n;i++){
        a.push_back({i, 0});
    }
    vector<pair<int,pair<int,int>>> j;
    for(int i = 0;i < m;i++){
        int x,y,p;
        cin >> x >> y;
        p = 1;
        x--;
        y--;
        j.push_back({p,{x,y}});
    }
    sort(j.begin(),j.end());
    for(int i = 0;i < m;i++){
        if (dfs(j[i].second.first) != dfs(j[i].second.second)){
            make(j[i].second.first,j[i].second.second);
            g[j[i].second.first].push_back(j[i].second.second);
            g[j[i].second.second].push_back(j[i].second.first);
        }
    }
    dfs(0, 1);
    int aa = 0;
    for(int i = 0;i < n;i++){
    	if(used[i] == 1){
    		aa++;
    	}
    }
    cout << min(aa, n - aa) << endl;
    for(int i = 0;i < n;i++){
    	if(aa <= n - aa && used[i] == 1){
    		cout << i + 1 << " ";
    	}
    	else if(aa > n - aa && used[i] == 2){ 
    		cout << i + 1 << " ";
    	}
    }
    cout << endl;
    
	
}
signed main() {
	int q;
	cin >> q;
	while(q--){
		solve();
	}
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <string>
#include <map>
#include <iomanip>

using namespace std;

vector< vector<int> > g;
vector<bool> used;
vector<int> ans;

void dfs(int v){
	used[v] = 1;
	for(int i =0; i < g[v].size(); i++){
		if(!used[g[v][i]]){
			ans.push_back(g[v][i]);
			dfs(g[v][i]);
			ans.push_back(v);
		}
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	g.resize(n);
	used.resize(n);
	for(int i =0; i < m; i++){
		int a, b;
		cin >> a >> b;
		g[a - 1].push_back(b- 1);
		g[b - 1].push_back(a -1);
	}
	ans.push_back(0);
	dfs(0);
	int mx = (2 * n - 1) /k + 1;
	int now = 0;
	for(int i =0; i < k; i++){
		if(now == ans.size()){
			cout << 1 << ' ' << 1 << '\n';
		}
		else{
			int sz = min(int(ans.size()) - now, mx);
			cout << sz << ' ';
			for(int i =0; i < sz; i++){
				cout << ans[now] + 1 <<  ' ';
				now++;
			}
			cout << '\n';
		}
	}
	return 0;
}
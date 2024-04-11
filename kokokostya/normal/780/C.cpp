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
vector<int> col;

void dfs(int v, int p){
	int cnt = 1;
	for(int i = 0; i < g[v].size(); i++){
		if(cnt == col[v])
			cnt++;
		if(cnt == col[p])
			cnt++;
		if(cnt == col[v])
			cnt++;
		if(g[v][i] != p){
			col[g[v][i]] = cnt;
			cnt++;
		}
	}
	for(int i = 0; i < g[v].size(); i++){
		if(g[v][i] != p)
			dfs(g[v][i], v);
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	g.resize(n);
	col.resize(n);
	for(int i =0; i < n -1; i++){
		int a, b;
		cin >> a >> b;
		g[a - 1].push_back(b - 1);
		g[b - 1].push_back(a - 1);
	}
	col[0]= 1;
	dfs(0, 0);
	int mx =0;
	for(int i =0; i < n; i++)
		mx = max(col[i], mx);
	cout << mx << '\n';
	for(int i =0;i < n; i++)
		cout << col[i] << ' ';
	return 0;
}
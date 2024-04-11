#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int cnt = 0, n;
vector<int> g[1000005];
int a[1000005], p, w[1000005];
void dfs(int u, int s){
	s = s + w[u];
	if (s < 0) s = 0;
	if (s>a[u]) return;
	cnt++;
	for (int i = 0; i < g[u].size(); i++)
		dfs(g[u][i],s);
}
int main(){
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 2; i <= n; i++) {
		cin >> p >> w[i];
		g[p].push_back(i);
	}
	dfs(1, 0);
	cout << n - cnt;
	return 0;
}
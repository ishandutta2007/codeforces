#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 1e6 + 10;
int n, k, ans;
vector<int> G[N], t[N];
int dfs(int u, int fa = 0) {
	if(G[u].size() == 1) return ans ++, 0;
	for(int v : G[u]) if(v ^ fa) t[u].push_back(dfs(v, u) + 1);
	sort(t[u].begin(), t[u].end());
	for(int i = 0; i + 1 < (int) t[u].size(); i ++) {
		if(t[u][i] + t[u][i + 1] <= k) ans --;
		else {
			return t[u][i];
		}
	}
	return t[u][(int) t[u].size() - 1];
}
int main() {
	scanf("%d%d", &n, &k);
	for(int u, v, i = 1; i < n; i ++) {
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i = 1; i <= n; i ++) {
		if(G[i].size() >= 2) {
			dfs(i); break ;
		}
	}
	printf("%d\n", ans); 
	return 0;
}
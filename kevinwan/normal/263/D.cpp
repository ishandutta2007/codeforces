#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MN = 1e5 + 5;
int k,d[MN];
vector<int> g[MN];
bool vis[MN],done;
vector<int> ans;
int lef;
void dfs(int x,int p) {
	vis[x] = 1;
	for (int y : g[x]) {
		if (y == p)continue;
		if (vis[y]) {
			if (d[x] - d[y] + 1 > k) {
				done = 1, ans.push_back(x), lef = d[x] - d[y];
				return;
			}
			continue;
		}
		d[y] = d[x] + 1;
		dfs(y,x);
		if (done) {
			if (lef)ans.push_back(x),lef--;
			return;
		}
	}
}
int main() {
	int n,m,i,a,b;
	scanf("%d%d%d", &n,&m,&k);
	for (i = 0; i < m; i++)scanf("%d%d", &a, &b), g[a].push_back(b), g[b].push_back(a);
	dfs(1,0);
	printf("%d\n", ans.size());
	for (int x : ans)printf("%d ", x);
}
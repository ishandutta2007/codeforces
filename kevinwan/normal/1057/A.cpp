#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<int> g[300001];
vector<int> ans;
int n;
bool dfs(int x) {
	if (x == n)return 1;
	for (int y : g[x]) {
		if (dfs(y)) {
			ans.push_back(x); return 1;
		}
	}
	return 0;
}
int main() {
	int i,x;
	scanf("%d", &n);
	for (i = 2; i <= n; i++)scanf("%d", &x), g[x].push_back(i);
	dfs(1);
	for (i = ans.size() - 1; i >= 0; i--)printf("%d ", ans[i]);
	printf("%d", n);
}
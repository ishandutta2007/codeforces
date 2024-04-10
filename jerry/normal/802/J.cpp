#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int> > ch[105];
int dst[105];
int n, ans;

void dfs(int at, int par)
{
	for (auto u: ch[at]) if (u.first != par)
	{
		dst[u.first] = dst[at] + u.second;
		dfs(u.first, at);
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1;i < n;i++)
	{
		int a, b, c; scanf("%d%d%d", &a, &b, &c);
		ch[a].emplace_back(b, c);
		ch[b].emplace_back(a, c);
	}
	dfs(0, 0);
	for (int i = 0;i < n;i++) ans = max(ans, dst[i]);
	printf("%d\n", ans);
	return 0;
}
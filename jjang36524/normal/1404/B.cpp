#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
vector<int>lin[100100];
int vis[100100];
int dep[100100];
void dfs(int n)
{
	int i;
	for (i = 0; i < lin[n].size(); i++)
	{
		if (!vis[lin[n][i]])
		{
			dep[lin[n][i]] = dep[n] + 1;
			vis[lin[n][i]] = 1;
			dfs(lin[n][i]);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int N, a, b, c, d;
		cin >> N >> a >> b >> c >> d;
		int i;
		for (i = 1; i <= N; i++)
			lin[i].clear();
		for (i = 1; i < N; i++)
		{
			int x, y;
			cin >> x >> y;
			lin[x].push_back(y);
			lin[y].push_back(x);
		}
		memset(vis, 0, sizeof(vis));
		memset(dep, 0, sizeof(dep));
		vis[a] = 1;
		dfs(a);
		if (dep[b] <=c)
			d = 0;
		memset(vis, 0, sizeof(vis));
		memset(dep, 0, sizeof(dep));
		vis[1] = 1;
		dfs(1);
		pair<int, int>len = { 0,0 };
		for (i = 1; i <= N; i++)
		{
			len = max(len, { dep[i],i });
		}
		memset(vis, 0, sizeof(vis));
		memset(dep, 0, sizeof(dep));
		vis[len.second] = 1;
		dfs(len.second);
		len = { 0,0 };
		for (i = 1; i <= N; i++)
		{
			len = max(len, { dep[i],i });
		}
		d = min(d, len.first);
		if (c * 2 >= d)
			cout << "Alice";
		else
			cout << "Bob";
		cout << '\n';
	}
}
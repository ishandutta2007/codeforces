#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> ch[100005];
ll deg[100005];
ll len[100005];
int n, m;

ll dfs(int at)
{
	if (len[at]) return len[at];
	for (int u: ch[at]) if (u < at) len[at] = max(len[at], dfs(u)+1);
	return len[at];
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0;i < m;i++)
	{
		int a, b; scanf("%d%d", &a, &b);
		--a, --b; ch[a].push_back(b); ch[b].push_back(a);
		deg[a]++, deg[b]++;
	}
	for (int i = 0;i < n;i++) dfs(i);
	ll ans = 0;
	for (int i = 0;i < n;i++) ans = max(ans, (len[i]+1ll)*deg[i]);
	cout << ans << endl;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int n, p[200005], b[200005], ans;
bool v[200005];

void dfs(int at)
{
	if (v[at]) return;
	v[at] = true;
	dfs(p[at]);
}

int main()
{
	scanf("%d", &n);
	for (int i = 0;i < n;i++) scanf("%d", p+i), p[i]--;
	for (int i = 0;i < n;i++) scanf("%d", b+i);
	for (int i = 0;i < n;i++) if (!v[i])
	{
		dfs(i);
		ans++;
	}
	if (ans == 1) ans = 0;
	int t = 0;
	for (int i = 0;i < n;i++) t ^= b[i];
	ans += !t;
	printf("%d\n", ans);
	return 0;
}
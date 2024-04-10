#include <bits/stdc++.h>
using namespace std;

int a[100005], b[100005], ans[200005], oth[200005];
int n;

void slv(int at)
{
	if (ans[at]) return;
	ans[at] = 1; ans[oth[at]] = 2;
	slv(oth[at]^1);
}

int main()
{
	scanf("%d", &n);
	for (int i = 0;i < n;i++)
	{
		scanf("%d%d", a+i, b+i), --a[i], --b[i];
		oth[a[i]] = b[i]; oth[b[i]] = a[i];
	}
	for (int i = 0;i < n;i++) if (!ans[a[i]]) slv(a[i]);
	for (int i = 0;i < n;i++) printf("%d %d\n", ans[a[i]], ans[b[i]]);
	return 0;
}
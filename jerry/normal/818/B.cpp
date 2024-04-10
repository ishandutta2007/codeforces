#include <bits/stdc++.h>
using namespace std;

bool use[105];
int p[105], l[105], n, m;

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0;i < n;i++) p[i] = -1;
	for (int i = 0;i < m;i++) scanf("%d", l+i), l[i]--;
	for (int i = 1;i < m;i++)
	{
		int v = (l[i]-l[i-1]+n)%n;
		if (v == 0) v += n;
		if (p[l[i-1]] == -1 || p[l[i-1]] == v) p[l[i-1]] = v;
		else
		{
			printf("-1\n");
			return 0;
		}
	}
	for (int i = 0;i < n;i++) if (p[i] != -1)
	{
		if (use[p[i]])
		{
			printf("-1\n");
			return 0;
		}
		use[p[i]] = true;
	}
	for (int i = 0;i < n;i++) if (p[i] == -1) for (int j = 1;j <= n;j++) if (!use[j])
	{
		p[i] = j;
		use[j] = true;
		break;
	}
	for (int i = 0;i < n;i++) printf("%d ", p[i]);
	printf("\n");
	return 0;
}
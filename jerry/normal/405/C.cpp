#include <cstdio>

int s[1000];
int ans;
int n;
int m;
int a;
int b;

int main()
{
	scanf("%d", &n);
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < i;j++)
			scanf("%d", &m);
		scanf("%d", s+i);
		ans += s[i];
		for (int j = i+1;j < n;j++)
			scanf("%d", &m);
	}
	scanf("%d", &m);
	while (m--)
	{
		scanf("%d", &a);
		if (a == 3)
			printf("%d", ans&1);
		else
		{
			scanf("%d", &b);
			ans -= s[b];
			s[b] = !s[b];
			ans += s[b];
		}
	}
	return 0;
}
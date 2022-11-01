#include <cstdio>
#include <algorithm>

int x[100];
int s;
int n;

int main()
{
	scanf("%d%d", &n, &s);
	for (int i = 0;i < n;i++)
		scanf("%d", x+i);
	std::sort(x, x+n);
	for (int i = 0;i < n-1;i++)
		s -= x[i];
	if (s < 0)
		printf("NO\n");
	else
		printf("YES\n");
	return 0;
}
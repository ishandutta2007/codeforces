#include <bits/stdc++.h>
using namespace std;

int a[200005], b[200005], n, o;

int main()
{
	scanf("%d", &n);
	for (int i = 0;i < n;i++)
	{
		scanf("%d", a+i);
		if (a[i] == 0) i--, n--;
	}
	n++;
	for (int i = 0;i < n;i++)
	{
		scanf("%d", b+i);
		if (b[i] == a[0]) o = i;
		if (b[i] == 0) i--, n--;
	}
	for (int i = 0;i < n;i++) if (a[i] != b[(i+o)%n])
	{
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	return 0;
}
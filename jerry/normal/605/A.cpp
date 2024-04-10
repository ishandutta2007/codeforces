#include <bits/stdc++.h>
using namespace std;

int o[100005], n;

int main()
{
	scanf("%d", &n);
	for (int i = 0;i < n;i++)
	{
		int x; scanf("%d", &x);
		o[--x] = i;
	}
	int b = 0, c = 1;
	for (int i = 1;i < n;i++)
		if (o[i] > o[i-1])
			c++;
		else
		{
			if (c > b) b = c;
			c = 1;
		}
	if (c > b) b = c;
	printf("%d\n", n-b);
	return 0;
}
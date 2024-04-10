#include <bits/stdc++.h>
using namespace std;

int x[500005];
int y[500005];
int l[500005];
int r[500005];
int n;

int main()
{
	scanf("%d", &n);
	for (int i = 0;i < n;i++) scanf("%d", x+i);
	int b = 0, c = 0;
	for (int i = 1;i < n-1;i++)
		if (x[i] != x[i-1] && x[i] != x[i+1])
		{
			c++;
			l[i] = r[i] = 1000000;
		} else
		{
			if (c > b) b = c;
			c = 0;
		}
	if (c > b)
		b = c;
	printf("%d\n", (b+1)/2);
	for (int i = 1;i < n;i++) if (l[i-1]+1 < l[i]) l[i] = l[i-1]+1;
	for (int i = n-2;i >= 0;i--) if (r[i+1]+1 < r[i]) r[i] = r[i+1]+1;
	for (int i = 0;i < n;i++)
		if (l[i])
		{
			if (l[i] <= r[i])
				y[i] = x[i-l[i]];
			else
				y[i] = x[i+r[i]];
		} else
			y[i] = x[i];
	for (int i = 0;i < n;i++)
		printf("%d ", y[i]); printf("\n");
	return 0;
}
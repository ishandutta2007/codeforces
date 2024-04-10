#include <bits/stdc++.h>
using namespace std;

char buf[8]; int d;
int p;
int n;

void rip()
{
	printf("NO\n");
	exit(0);
}

int main()
{
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d%s", &d, buf);
		if (buf[0] == 'E' || buf[0] == 'W')
		{
			if (p == 0 || p == 20000) rip();
			continue;
		}
		if (buf[0] == 'N') p -= d;
		else p += d;
		if (p < 0 || p > 20000) rip();
	}
	if (p) rip();
	printf("YES\n");
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int p[500005], q[500005];
char buf[500005];
int n, a, b, t;

int main()
{
	scanf("%d%d%d%d%s", &n, &a, &b, &t, buf);
	p[0] = 0; if (buf[0] == 'w') p[0] += b;
	for (int i = 1;i < n;i++)
	{
		p[i] = p[i-1] + a;
		if (buf[i] == 'w') p[i] += b;
	}
	q[n-1] = a; if (buf[n-1] == 'w') q[n-1] += b;
	for (int i = n-2;i > 0;i--)
	{
		q[i] = q[i+1] + a;
		if (buf[i] == 'w') q[i] += b;
	}
	int ans = 0, j = n;
	for (int i = n-1;i >= 0;i--)
	{
		for (;j-1 > i;j--) if (p[i]+i*a+q[j-1]+i+n-j+1 > t)
			break;
		if (p[i]+i*a+q[j]+i+n-j+1 <= t)
			ans = max(ans, i+n-j+1);
	}
	j = 1;
	for (int i = 0;i < n;i++)
	{
		if (j == i) j++;
		for (;j < n;j++) if (q[j]+(n-j)*a+p[i]+i+n-j+1 <= t)
			break;
		if (q[j]+(n-j)*a+p[i]+i+n-j+1 <= t)
			ans = max(ans, i+n-j+1);
	}
	printf("%d\n", ans);
	return 0;
}
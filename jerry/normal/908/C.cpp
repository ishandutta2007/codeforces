#include <bits/stdc++.h>
using namespace std;

double ans[1005];
int n, r, x[1005];

int main()
{
	scanf("%d%d", &n, &r);
	for (int i = 0;i < n;i++)
	{
		scanf("%d", x+i);
		ans[i] = r;
		for (int j = 0;j < i;j++)
			ans[i] = max(ans[i], ans[j]+sqrt(4*r*r-(x[i]-x[j])*(x[i]-x[j])));
	}
	for (int i = 0;i < n;i++) printf("%.10lf%c", ans[i], " \n"[i==n-1]);
	return 0;
}
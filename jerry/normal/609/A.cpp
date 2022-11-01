#include <bits/stdc++.h>
using namespace std;

int n, m, a[105];

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0;i < n;i++) scanf("%d", a+i);
	sort(a, a+n, greater<int>());
	for (int i = 0;i < n;i++) if ((m-=a[i]) <= 0)
	{
		printf("%d\n", i+1);
		return 0;
	}
}
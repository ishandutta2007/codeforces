#include <bits/stdc++.h>
using namespace std;

const int MAXN=105;

int a[MAXN];

int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=n;i>=1;i--)
		for (int j=1;j<i;j++)
			if (a[j]>a[j+1])
			{
				swap(a[j],a[j+1]);
				printf("%d %d\n",j,j+1);
			}
	return 0;
}
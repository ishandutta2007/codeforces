#include <bits/stdc++.h>
using namespace std;

const int MAXN=200005;

int a[MAXN],vis[MAXN];

int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	int r=0,cnt=0;
	for (int i=1;i<=n;i++)
		if (a[i]==i)
		{
			r=i;
			break;
		}
	for (int i=1;i<=n;i++)
		if (!vis[i])
		{
			vis[i]=i;
			int p;
			for (p=a[i];p!=i;p=a[p])
			{
				if (vis[p]) break;
				vis[p]=i;
			}
			if (a[p]!=p&&vis[p]==i)
			{
				cnt++;
				if (r) a[p]=r;
				else r=a[p]=p;
			}
		}
	for (int i=1;i<=n;i++)
		if (a[i]==i&&i!=r)
		{
			a[i]=r;
			cnt++;
		}
	printf("%d\n",cnt);
	for (int i=1;i<=n;i++) printf("%d ",a[i]);
	return 0;
}
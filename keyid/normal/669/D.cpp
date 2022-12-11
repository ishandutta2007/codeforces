#include <bits/stdc++.h>
using namespace std;

const int MAXN=1000005;

typedef long long LL;

int ans[MAXN];

int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	LL c0=0,c1=0;
	for (int op,x;q--;)
	{
		scanf("%d",&op);
		if (op==1)
		{
			scanf("%d",&x);
			c0+=x;
			c1+=x;
		}
		else
		{
			if ((c0)%2==0)
			{
				c0++;
				c1--;
			}
			else
			{
				c0--;
				c1++;
			}
		}
	}
	c0%=n;c1%=n;
	for (int i=1;i<=n;i++)
		if (i&1) ans[(i-1+c0+n)%n+1]=i;
		else ans[(i-1+c1+n)%n+1]=i;
	for (int i=1;i<=n;i++) printf("%d ",ans[i]);
	return 0;
}
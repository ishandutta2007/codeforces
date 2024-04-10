#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define per(i,n) for ((i)=n;(i)>=(1);(i)--)
using namespace std;

int n,m;
int a[500005],c[35],s[500005],ans;

int main()
{
	int i,j;
	scanf("%d",&n);
	rep(i,n) scanf("%d",&a[i]);
	
	rep(i,n)
	{
		for (j=0;j<=30;j++) if ((a[i]>>j)&1)
		{
			c[j]++;
		}
	}
	rep(i,n)
	{
		for (j=0;j<=30;j++) if ((a[i]>>j)&1)
		{
			if (c[j]==1) s[i]|=(1<<j);
		}
	}
	
	ans=1;
	rep(i,n)
	{
		if (s[i]>s[ans]) ans=i;
	}
	
	printf("%d",a[ans]);
	rep(i,n) if (i!=ans)
	{
		printf(" %d",a[i]);
	}
	puts("");
	
	return 0;
}
#include<bits/stdc++.h>

int a[10005];

int main()
{
	int n,m,i;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)scanf("%d",a+i);
	while(m--)
	{
		int l,r,x;
		scanf("%d%d%d",&l,&r,&x);
		int now=x-l;
		for(i=l;i<=r;++i)
		if(a[i]<a[x])--now;
		if(now==0) puts("Yes");
		else puts("No");
	}
}
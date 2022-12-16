#include<bits/stdc++.h>
using namespace std;
const int N=1000;
int n,m,a[N],b[N],c[N],p[N],t,i;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;++i)
			scanf("%d",&a[i]);
		for(i=1;i<=n;++i)
			scanf("%d",&b[i]);
		for(i=1;i<=n;++i)
			scanf("%d",&c[i]);
		p[1]=a[1];
		for(i=2;i<n;++i)
			if(a[i]!=p[i-1])
				p[i]=a[i];
			else
				p[i]=b[i];
		if(a[n]!=p[n-1]&&a[n]!=p[1])
			p[n]=a[n];
		else
			if(b[n]!=p[n-1]&&b[n]!=p[1])
				p[n]=b[n];
			else
				p[n]=c[n];
		for(i=1;i<=n;++i)
			printf("%d ",p[i]);
		printf("\n");
	}
}
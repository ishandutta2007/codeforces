#include<bits/stdc++.h>
using namespace std;
const int N=1000;
int n,m,a[N],b[N],c[N],p[N],t,i,s,k;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&k);
		int s=0;
		bool flag=true;
		for(i=1;i<=n;++i)
		{
			scanf("%d",&a[i]);
			b[i]=a[i]-a[i-1];
			if(a[i]!=a[1])
				flag=false;
			if(b[i]>0&&i>1)
				++s;
		}
		if(flag)
		{
			puts("1");
			continue;
		}
		if(k==1)
			puts("-1");
		else
			printf("%d\n",(s+k-2)/(k-1));
	}
}
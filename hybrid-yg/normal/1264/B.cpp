#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ri register int
const long double PI=3.141592653589793238462643383279;
const int M=998244353,N=200005;
const long long inf=1000000000000000000ll;
int a,b,c,d,i,ans[500005],k;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d %d %d %d",&a,&b,&c,&d);
	int ta=a,tb=b,tc=c,td=d;
	while(a&&b)
	{
		--a;
		--b;
		ans[++k]=0;
		ans[++k]=1;
	}
	if(c==0&&d==0)
	{
		if(a>1||b>1)
		{
			printf("NO");
			return 0;
		}
		printf("YES\n");
		if(b==1)
			printf("1 ");
		for(i=1;i<=k;++i)
			printf("%d ",ans[i]);
		if(a==1)
			printf("0 ");
		return 0;
	}
	while(c&&d)
	{
		ans[++k]=2;
		ans[++k]=3;
		--c;
		--d;
	}
	while(b&&c)
	{
		ans[++k]=2;
		ans[++k]=1;
		--b;
		--c;
	}
	if(c)
	{
		--c;
		ans[++k]=2;
	}
	if(a==0&&b<=1&&c==0&&d==0)
	{
		puts("YES");
		if(b==1)
			printf("1 ");
		for(i=1;i<=k;++i)
			printf("%d ",ans[i]);
		return 0;
	}
	a=td;
	b=tc;
	c=tb;
	d=ta;
	k=0;
	while(a&&b)
	{
		--a;
		--b;
		ans[++k]=0;
		ans[++k]=1;
	}
	if(c==0&&d==0)
	{
		if(a>1||b>1)
		{
			printf("NO");
			return 0;
		}
		printf("YES\n");
		if(b==1)
			printf("2 ");
		for(i=1;i<=k;++i)
			printf("%d ",4-ans[i]-1);
		if(a==1)
			printf("3 ");
		return 0;
	}
	while(c&&d)
	{
		ans[++k]=2;
		ans[++k]=3;
		--c;
		--d;
	}
	while(b&&c)
	{
		ans[++k]=2;
		ans[++k]=1;
		--b;
		--c;
	}
	if(c)
	{
		--c;
		ans[++k]=2;
	}
	if(a==0&&b<=1&&c==0&&d==0)
	{
		puts("YES");
		if(b==1)
			printf("2 ");
		for(i=1;i<=k;++i)
			printf("%d ",4-ans[i]-1);
		return 0;
	}
	/*a=ta,b=tb,c=tc,d=td;
	if(a&&b&&c&&d)
	{
		--a,--b,--c,--d;
		ans[++k]=0,ans[++k]=1,ans[++k]=2,ans[++k]=3;
	}
	for(i=1;i<=n;++i)
	{
		if(i&1)
		{
			if(b&&c&&d)
				ans[++k]=2,ans[++k]=1,ans[++k]=0;
			else
				break;
		}
		else
		{
			if(a&&b&&c)
				ans[++k]=0,ans[++k]=1,ans[++k]=2;
			else
				break;
		}
	}
	*/
	puts("NO");
}
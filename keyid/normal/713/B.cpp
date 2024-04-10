#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int main()
{
	LL n;
	scanf("%lld",&n);
	int ret,bit=1;
	LL xl[2],xr[2],yl[2],yr[2];
	while ((1LL<<bit)<=n) bit++;bit--;
	for (int j=0;j<2;j++)
	{
		xl[j]=n+1;
		for (int i=bit;i>=0;i--)
		{
			if (xl[j]-(1LL<<i)<1) continue;
			printf("? %lld 1 %lld %lld\n",xl[j]-(1LL<<i),n,n);
			fflush(stdout);
			scanf("%d",&ret);
			if (ret<=j) xl[j]-=1LL<<i;
		}
		xl[j]--;
	}
	for (int j=0;j<2;j++)
	{
		xr[j]=0;
		for (int i=bit;i>=0;i--)
		{
			if (xr[j]+(1LL<<i)>n) continue;
			printf("? 1 1 %lld %lld\n",xr[j]+(1LL<<i),n);
			fflush(stdout);
			scanf("%d",&ret);
			if (ret<=j) xr[j]+=1LL<<i;
		}
		xr[j]++;
	}
	for (int j=0;j<2;j++)
	{
		yl[j]=n+1;
		for (int i=bit;i>=0;i--)
		{
			if (yl[j]-(1LL<<i)<1) continue;
			printf("? 1 %lld %lld %lld\n",yl[j]-(1LL<<i),n,n);
			fflush(stdout);
			scanf("%d",&ret);
			if (ret<=j) yl[j]-=1LL<<i;
		}
		yl[j]--;
	}
	for (int j=0;j<2;j++)
	{
		yr[j]=0;
		for (int i=bit;i>=0;i--)
		{
			if (yr[j]+(1LL<<i)>n) continue;
			printf("? 1 1 %lld %lld\n",n,yr[j]+(1LL<<i));
			fflush(stdout);
			scanf("%d",&ret);
			if (ret<=j) yr[j]+=1LL<<i;
		}
		yr[j]++;
	}
	int ans[3];
	for (ans[0]=0;ans[0]<2;ans[0]++)
		for (ans[1]=0;ans[1]<2;ans[1]++)
			for (ans[2]=0;ans[2]<2;ans[2]++)
				{
					int &i=ans[0],&j=ans[1],&k=ans[2];
					if (xl[0]>xr[i]||yl[j]>yr[k]) continue;
					printf("? %lld %lld %lld %lld\n",xl[0],yl[j],xr[i],yr[k]);
					fflush(stdout);
					scanf("%d",&ret);
					if (ret!=1) continue;
					if (xl[0]<xr[i])
					{
						printf("? %lld %lld %lld %lld\n",xl[0]+1,yl[j],xr[i],yr[k]);
						fflush(stdout);
						scanf("%d",&ret);
						if (ret==1) continue;
						printf("? %lld %lld %lld %lld\n",xl[0],yl[j],xr[i]-1,yr[k]);
						fflush(stdout);
						scanf("%d",&ret);
						if (ret==1) continue;
					}
					if (yl[j]<yr[k])
					{
						printf("? %lld %lld %lld %lld\n",xl[0],yl[j]+1,xr[i],yr[k]);
						fflush(stdout);
						scanf("%d",&ret);
						if (ret==1) continue;
						printf("? %lld %lld %lld %lld\n",xl[0],yl[j],xr[i],yr[k]-1);
						fflush(stdout);
						scanf("%d",&ret);
						if (ret==1) continue;
					}
					goto label;
				}
	label:
	putchar('!');
	for (int i=0;i<2;i++)
		printf(" %lld %lld %lld %lld",xl[i],yl[ans[1]^i],xr[ans[0]^i],yr[ans[2]^i]);
	fflush(stdout);
	return 0;
}
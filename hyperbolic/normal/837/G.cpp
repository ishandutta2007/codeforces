#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#define SIZE 300
#define MOD 1000000000

long long int sum1[260][200010],sum2[260][200010];

struct str{
	long long int x1;
	long long int x2;
	long long int x3;
	long long int x4;
	long long int x5;
	long long int x6;
}save[75010];

int main()
{
	long long int a;
	scanf("%d",&a);
	for(long long int i=1;i<=a;i++)
	{
		long long int b,c,d,e,f,g;
		scanf("%lld%lld%lld%lld%lld%lld",&b,&c,&d,&e,&f,&g);
		save[i] = {b,c,d,e,f,g};
	}
	
	for(long long int i=1;i<=a;i++)
	{
		sum1[i/SIZE][0] += save[i].x3, sum1[i/SIZE][save[i].x1+1] -= save[i].x3;
		sum1[i/SIZE][save[i].x1+1] += save[i].x5, sum1[i/SIZE][save[i].x2+1] -= save[i].x5;
		sum2[i/SIZE][save[i].x1+1] += save[i].x4, sum2[i/SIZE][save[i].x2+1] -= save[i].x4;
		sum1[i/SIZE][save[i].x2+1] += save[i].x6, sum1[i/SIZE][200002] -= save[i].x6;
	}
	for(long long int j=0;j<=250;j++)
	{
		for(long long int i=1;i<=200002;i++)
		{
			sum1[j][i] += sum1[j][i-1];
			sum2[j][i] += sum2[j][i-1];
		}
	}
	
	long long int last = 0;
	long long int b;
	scanf("%lld",&b);
	for(long long int i=1;i<=b;i++)
	{
		long long int c,d;
		long long int e;
		scanf("%lld%lld%lld",&c,&d,&e);
		e = (e+last)%MOD;
		long long int f = e;
		if(f>200000) f = 200001;
		
		long long int ans = 0;
		if(d-c<=SIZE)
		{
			for(long long int j=c;j<=d;j++)
			{
				if(e<=save[j].x1) ans += save[j].x3;
				else if(e>save[j].x2) ans += save[j].x6;
				else ans += (save[j].x4*e + save[j].x5);
			}
			printf("%lld\n",ans);
			last = ans%MOD;
		}
		else
		{
			long long int L,R;
			for(long long int k=0;k<=250;k++)
			{
				if(k*SIZE <= c && c<(k+1)*SIZE)
				{
					for(int j=c;j<(k+1)*SIZE;j++)
					{
						if(e<=save[j].x1) ans += save[j].x3;
						else if(e>save[j].x2) ans += save[j].x6;
						else ans += (save[j].x4*e + save[j].x5);
					}
					L = k+1;
					break;
				}
			}
			for(long long int k=250;k>=0;k--)
			{
				if(k*SIZE <= d && d<(k+1)*SIZE)
				{
					for(int j=d;j>=k*SIZE;j--)
					{
						if(e<=save[j].x1) ans += save[j].x3;
						else if(e>save[j].x2) ans += save[j].x6;
						else ans += (save[j].x4*e + save[j].x5);
					}
					R = k-1;
					break;
				}
			}
			for(long long int j=L;j<=R;j++) ans += (sum2[j][f]*e + sum1[j][f]);
			printf("%lld\n",ans);
			last = ans%MOD;
		}
	}
}
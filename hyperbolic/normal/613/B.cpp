#include <stdio.h>
#include <algorithm>
struct str{
	int x0;
	int number;
}x[100010],y[100010],z[100010];
long long int ans2;
long long int ans[100010];
bool cmp(str a, str b)
{
	if(a.x0==b.x0) return a.number<b.number;
	return a.x0<b.x0;
}
int main()
{
	int a,b,c,d,f,i,min,s,t;
	long long int e,sum;
	scanf("%d%d%d%d%I64d",&a,&b,&c,&d,&e);
	sum=e;
	for(i=1;i<=a;i++)
	{
		scanf("%d",&f);
		x[i]={f,i};
		sum+=f;
	}
	if(sum>=(long long int)b*a)
	{
		printf("%I64d\n",(long long int)a * c + (long long int)b * d);
		for(i=1;i<=a;i++) printf("%d ",b);
		return 0;
	}
	std::sort(x+1,x+a+1,cmp);
	for(i=1;i<=a;i++) y[i]=x[i];
	
	
	for(i=a;i>=1;i--)
	{
		if(e>=(b-y[i].x0)) e-=(b-y[i].x0);
		else break;
	}
	s = i;
	for(min=1;min<=s;min++)
	{
		if(min==s)
		{
			if((long long int)min*(b-y[min].x0)<=e) e-= (long long int)min*(b - y[min].x0);
			else break;
		}
		else
		{
			if((long long int)min*(y[min+1].x0-y[min].x0)<=e) e -= (long long int)min*(y[min+1].x0-y[min].x0);
			else break;
		}
	}
	t = y[min].x0 + e/min;
	ans2 = (long long int)t*d + (long long int)(a-s)*c;
	for(i=1;i<=min;i++) z[i]={t,y[i].number};
	for(i=min+1;i<=s;i++) z[i]=y[i];
	for(i=s+1;i<=a;i++) z[i]={b,y[i].number};
	while(1)
	{
		s++;
		if(s>a) break;
		e += (b-y[s].x0);
		for(;min<=s;min++)
		{
			if(min==s)
			{
				if((long long int)min*(b-y[min].x0)<=e) e-=(long long int)min*(b-y[min].x0);
				else
				{
					t = y[min].x0 + e/min;
					if(t*d + (a-s)*c >ans2)
					{
						ans2 = (long long int)t*d + (long long int)(a-s)*c;
						for(i=1;i<=min;i++) z[i]={t,y[i].number};
						for(i=min+1;i<=s;i++) z[i]=y[i];
						for(i=s+1;i<=a;i++) z[i]={b,y[i].number};
					}
					break;
				}
			}
			else
			{
				if((long long int)min*(y[min+1].x0-y[min].x0)<=e) e-= (long long int)min*(y[min+1].x0-y[min].x0);
				else
				{
					t = y[min].x0 + e/min;
					if((long long int)t*d + (long long int)(a-s)*c >ans2)
					{
						ans2 = (long long int)t*d + (long long int)(a-s)*c;
						for(i=1;i<=min;i++) z[i]={t,y[i].number};
						for(i=min+1;i<=s;i++) z[i]=y[i];
						for(i=s+1;i<=a;i++) z[i]={b,y[i].number};
					}
					break;
				}
			}
		}
	}
	printf("%I64d\n",ans2);
	for(i=1;i<=a;i++) ans[z[i].number]=z[i].x0;
	for(i=1;i<=a;i++) printf("%d ",ans[i]);
}
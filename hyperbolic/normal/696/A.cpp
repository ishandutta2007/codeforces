#include <stdio.h>
struct str{
	long long int x0;
	long long int y0;
	long long int count;
}query[2010];
int t = 1;
str makeQuery(long long int a, long long int b, long long int c)
{
	str A;
	A.x0 = a;
	A.y0 = b;
	A.count = c;
	return A;
}
int main()
{
	int a,b;
	long long int c,d,e;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		scanf("%d",&b);
		if(b==1)
		{
			scanf("%I64d%I64d%I64d",&c,&d,&e);
			long long int c2,d2;
			c2 = c, d2 = d;
			while(c2!=d2)
			{
				if(c2>d2) c2/=2;
				else d2/=2;
			}
			query[t++] = makeQuery(c2,c,e);
			query[t++] = makeQuery(d2,d,e);
		}
		else if(b==2)
		{
			scanf("%I64d%I64d",&c,&d);
			long long int c2,d2;
			long long int ans=0;
			c2 = c, d2 = d;
			while(c2!=d2)
			{
				if(c2>d2) c2/=2;
				else d2/=2;
			}
			for(int j=1;j<t;j++)
			{
				long long int p = query[j].y0;
				long long int q = c;
				while(p!=q)
				{
					if(p>q) p/=2;
					else q/=2;
				}
				while(p>query[j].x0&&p>c2) ans+=query[j].count,p/=2;
			}
			for(int j=1;j<t;j++)
			{
				long long int p = query[j].y0;
				long long int q = d;
				while(p!=q)
				{
					if(p>q) p/=2;
					else q/=2;
				}
				while(p>query[j].x0&&p>c2) ans+=query[j].count,p/=2;
			}
			printf("%I64d\n",ans);
		}
	}
}
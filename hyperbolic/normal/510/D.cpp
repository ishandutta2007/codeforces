#include <stdio.h>
#include <queue>
#include <map>
struct str{
	int value;
	int count;
}x[310];
bool operator<(str a,str b)
{
	if(a.count==b.count) return a.value>b.value;
	return a.count>b.count;
}
std::priority_queue<str> Q;
std::map<int,int> Map;
int gcd(int a, int b)
{
	return a?gcd(b%a,a):b;
}
int check[40010],Prime[40010],p=1;
int main()
{
	int a,i,j,b,c,d,m=0;
	for(i=2;i<=40000;i++)
	{
		if(check[i]==0)
		{
			Prime[p++]=i;
			for(j=i;j<=40000;j+=i) check[j]=1;
		}
	}
	scanf("%d",&a);
	for(i=1;i<=a;i++)
	{
		scanf("%d",&b);
		for(j=1;j<p;j++)
		{
			while(b%(Prime[j]*Prime[j])==0) b/=Prime[j];
		}
		x[i].value=b;
	}
	for(i=1;i<=a;i++) scanf("%d",&x[i].count);
	for(i=1;i<=a;i++) m=gcd(m,x[i].value);
	if(m!=1)
	{
		printf("-1");
		return 0;
	}
	for(i=1;i<=a;i++) Q.push(x[i]);
	while(!Q.empty())
	{
		b=Q.top().value;
		c=Q.top().count;
		//printf("%d %d\n",b,c);
		Q.pop();
		if(Map[b]) continue;
		Map[b]=1;
		if(b==1)
		{
			printf("%d",c);
			return 0;
		}
		for(i=1;i<=a;i++)
		{
			d=gcd(b,x[i].value);
			if(Map[d]) continue;
			Q.push({d,c+x[i].count});
		}
	}
}
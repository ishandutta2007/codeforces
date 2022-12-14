#include <stdio.h>

long long int MAX = 1;
int a,b;
long long int c,d,e;
int x[200010],y[200010],pos[200010],check[200010];

long long int func(int k)
{
	if(k==b+1) return 0;
	
	if(pos[k+1]==pos[k]+1) return func(k+1);
	else
	{
		int size = pos[k+1]-pos[k]-1;
		if(size<d)
		{
			int max = 0;
			for(int i=pos[k]+1;i<=pos[k+1]-1;i++) max = max>x[i]?max:x[i];
			if(max<x[pos[k]] || max<x[pos[k+1]]) return func(k+1) + size*e;
			else return MAX;
		}
		else
		{
			if(d*e>=c) return func(k+1) + (size/d)*c + (size%d)*e;
			else
			{
				int max = 0;
				for(int i=pos[k]+1;i<=pos[k+1]-1;i++) max = max>x[i]?max:x[i];
				if(max<x[pos[k]] || max<x[pos[k+1]]) return func(k+1) + size*e;
				else return func(k+1) + (size-d)*e + c;
			}
		}
	}
}
int main()
{
	for(int i=1;i<=16;i++) MAX*=10;
	
	scanf("%d%d%lld%lld%lld",&a,&b,&c,&d,&e);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=b;i++) scanf("%d",&y[i]);
	for(int i=1;i<=a;i++) check[x[i]] = i;
	
	for(int i=1;i<=b;i++)
	{
		pos[i] = check[y[i]];
		if(pos[i]==0)
		{
			printf("-1");
			return 0;
		}
	}
	x[a+1] = 0;
	x[0] = 0;
	pos[b+1] = a+1;
	pos[0] = 0;
	
	for(int i=1;i<=b;i++)
	{
		if(pos[i]>pos[i+1])
		{
			printf("-1");
			return 0;
		}
	}
	
	long long int ans = func(0);
	if(ans>=MAX) printf("-1");
	else printf("%lld",ans);
}
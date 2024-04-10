#include <stdio.h>
#include <algorithm>
struct str{
	int x0;
	int y0;
	int z0;
}x[1010];
int next[1010],ans[1010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		int c,d,e;
		scanf("%d%d%d",&c,&d,&e);
		x[i]={c,d,e};
		if(c==1) for(int j=d;j<e;j++) next[j] = 1;
	}
	for(int i=1;i<=a;i++) ans[i] = a-i+1;
	
	int p = 0;
	for(int i=1;i<=a;i++)
	{
		if(next[i]==1 && next[i-1]==0) p = i;
		if(next[i]==0 && p!=0)
		{
			std::reverse(ans+p,ans+i+1);
			p = 0;
		}
	}
	for(int j=1;j<=b;j++)
	{
		int count=0;
		for(int i=x[j].y0;i<x[j].z0;i++)
		{
			if(ans[i]>ans[i+1]) count++;
		}
		if(x[j].x0==1&&count>0)
		{
			printf("NO");
			return 0;
		}
		if(x[j].x0==0&&count==0)
		{
			printf("NO");
			return 0;
		}
	}
	printf("YES\n");
	for(int i=1;i<=a;i++) printf("%d ",ans[i]);
}
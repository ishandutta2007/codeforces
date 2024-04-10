#include <stdio.h>

int next[500010],size[500010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	
	for(int i=1;i<=a;i++) next[i] = i, size[i] = 1;
	
	for(int i=1;i<=b;i++)
	{
		int c;
		scanf("%d",&c);
		if(c==0) continue;
		
		int d;
		scanf("%d",&d);
		for(int j=2;j<=c;j++)
		{
			int e;
			scanf("%d",&e);
			int s = d;
			int t = e;
			while(next[d]!=d) d = next[d];
			while(next[e]!=e) e = next[e];
			if(d==e) continue;
			if(size[d]>size[e])
			{
				next[e] = d;
				size[d] += size[e];
			}
			else
			{
				next[d] = e;
				size[e] += size[d];
			}
		}
	}
	
	for(int i=1;i<=a;i++)
	{
		int t = i;
		while(next[t]!=t) t = next[t];
		printf("%d ",size[t]);
	}
}
#include <stdio.h>

int next[500010],check[500010],ans[500010];
int find(int k)
{
	if(k==next[k]) return k;
	else return next[k] = find(next[k]);
}

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b;
		scanf("%d",&b);
		if(b==1)
		{
			int c;
			scanf("%d",&c);
			if(check[c]==0)
			{
				check[c] = i;
				next[i] = i;
			}
			else next[i] = find(check[c]);
		}
		else
		{
			int c,d;
			scanf("%d%d",&c,&d);
			if(c==d) continue;
			if(check[c]==0) continue;
			else if(check[d]==0)
			{
				check[d] = check[c];
				check[c] = 0;
			}
			else
			{
				int c2 = find(check[c]), d2 = find(check[d]);
				next[c2] = d2;
				check[c] = 0;
			}
		}
	}
	
	for(int i=1;i<=500000;i++)
	{
		if(check[i]>0)
		{
			int d = check[i];
			ans[d] = i;
		}
	}
	
	for(int i=1;i<=a;i++)
	{
		if(next[i]==0) continue;
		printf("%d ",ans[find(i)]);
	}
}
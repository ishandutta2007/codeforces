#include <stdio.h>

int x[200010],next[200010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	next[a] = a+1;
	for(int i=a-1;i>=1;i--)
	{
		if(x[i]==x[i+1]) next[i] = next[i+1];
		else next[i] = i+1;
	}
	
	for(int i=1;i<=b;i++)
	{
		int c,d,e;
		scanf("%d%d%d",&c,&d,&e);
		if(x[c]!=e) printf("%d\n",c);
		else
		{
			if(next[c]>d) printf("-1\n");
			else printf("%d\n",next[c]);
		}
	}
}
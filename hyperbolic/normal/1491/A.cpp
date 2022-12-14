#include <stdio.h>

int x[100010],count[3];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) count[x[i]]++;
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		if(c==1)
		{
			count[x[d]]--;
			x[d] = 1-x[d];
			count[x[d]]++;
		}
		else
		{
			if(count[1]>=d) printf("1\n");
			else printf("0\n");
		}
	}
}
#include <stdio.h>
int ans[100010];
int pow(int k)
{
	return 1<<k;
}
int main()
{
	int a,b,c,d;
	scanf("%d%d",&a,&b);
	ans[1] = 1;
	ans[a] = 2;
	for(int i=1;i<=b;i++)
	{
		scanf("%d%d",&c,&d);
		if(c>d)
		{
			int t = c;
			c = d;
			d = t;
		}
		if(ans[c]==2)
		{
			printf("0");
			return 0;
		}
		if(ans[d]==1)
		{
			printf("0");
			return 0;
		}
		ans[c] = 1;
		ans[d] = 2;
	}
	
	int i,j;
	for(i=a;i>=1;i--) if(ans[i]==1) break;
	for(j=1;j<=a;j++) if(ans[j]==2) break;
	if(i>j)
	{
		printf("0");
		return 0;
	}
	printf("%d",j-i);
}
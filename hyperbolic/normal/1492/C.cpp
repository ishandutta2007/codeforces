#include <stdio.h>

char x[200010],y[200010];
int left[200010],right[200010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	scanf("%s%s",x+1,y+1);
	
	int p = 1;
	for(int i=1;i<=a;i++)
	{
		if(x[i]==y[p])
		{
			left[p] = i;
			p++;
		}
	}
	p = b;
	for(int i=a;i>=1;i--)
	{
		if(x[i]==y[p])
		{
			right[p] = i;
			p--;
		}
	}
	
	int ans = 0;
	for(int i=1;i<b;i++)
	{
		int s = left[i];
		int t = right[i+1];
		ans = ans>t-s?ans:t-s;
	}
	printf("%d",ans);
}
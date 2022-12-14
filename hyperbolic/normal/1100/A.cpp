#include <stdio.h>

int x[110];
int abs(int k)
{
	return k>0?k:-k;
}
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	int count1 = 0, count2 = 0;
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++)
	{
		if(x[i]==1) count1++;
		else count2++;
	}
	
	int ans = 0;
	for(int i=1;i<=b;i++)
	{
		int s = count1, t = count2;
		for(int j=i;j<=a;j+=b)
		{
			if(x[j]==1) s--;
			else t--;
		}
		ans = ans>abs(s-t)?ans:abs(s-t);
	}
	printf("%d",ans);
}
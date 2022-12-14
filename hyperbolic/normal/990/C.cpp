#include <stdio.h>
#include <string.h>

long long int count[300010],count2[300010];
char x[300010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		scanf("%s",x+1);
		int b = strlen(x+1);
		int sum = 0;
		int min = 0;
		for(int j=1;j<=b;j++)
		{
			if(x[j]=='(') sum++;
			else sum--;
			min = min<sum?min:sum;
		}
		if(sum>0)
		{
			if(min==0) count[sum]++;
		}
		else if(sum==0)
		{
			if(min==0) count[sum]++;
		}
		else
		{
			if(min>=sum) count2[-sum]++;
		}
	}
	
	long long int ans = 0;
	for(int i=1;i<=300000;i++) ans += count[i]*count2[i];
	ans += count[0]*count[0];
	printf("%lld",ans);
}
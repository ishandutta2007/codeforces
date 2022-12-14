#include <stdio.h>
#include <algorithm>

int x[110];
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=b;i++) scanf("%d",&x[i]);
	std::sort(x+1,x+b+1);
	
	long long int sum = 0;
	for(int i=1;i<=b;i++) sum += x[i];
	
	int ans = 0;
	for(int i=0;i<=a;i++)
	{
		long long int s = c - (i*sum);
		int count = i*(b+1);
		if(s<0) break;
		for(int j=1;j<=b;j++)
		{
			for(int k=i+1;k<=a;k++)
			{
				s -= x[j];
				if(s<0) goto u;
				count++;
			}
		}
		u:;
		ans = ans>count?ans:count;
	}
	printf("%d",ans);
}
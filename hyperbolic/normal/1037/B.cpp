#include <stdio.h>
#include <algorithm>

int x[200010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	std::sort(x+1,x+a+1);
	int c = (a+1)/2;
	
	long long int ans = 0;
	if(x[c]==b)
	{
		printf("0");
		return 0;
	}
	else if(x[c]>b)
	{
		for(int i=c;i>=1;i--)
		{
			if(x[i]>b) ans += (x[i]-b);
			else break;
		}
		printf("%lld",ans);
	}
	else
	{
		for(int i=c;i<=a;i++)
		{
			if(x[i]<b) ans += (b-x[i]);
			else break;
		}
		printf("%lld",ans);
	}
}
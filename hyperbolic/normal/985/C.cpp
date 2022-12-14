#include <stdio.h>
#include <algorithm>

int x[100010];
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=a*b;i++) scanf("%d",&x[i]);
	std::sort(x+1,x+a*b+1);
	int R;
	for(int i=a*b;i>=1;i--)
	{
		if(x[i]<=x[1]+c)
		{
			R = i;
			break;
		}
	}	
	if(R<a)
	{
		printf("0");
		return 0;
	}
	
	long long int ans = 0;
	for(int i=1;i<=a;i++)
	{
		int p = (i-1)*b+1 < i+(R-a)?(i-1)*b+1 : i+(R-a);
		ans += x[p];
	}
	
	printf("%lld",ans);
}
#include <stdio.h>
#include <algorithm>

int x[1010],y[1010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++)
		{
			int b,c;
			scanf("%d%d",&b,&c);
			x[i] = b, y[i] = c;
		}
		std::sort(x+1,x+a+1);
		std::sort(y+1,y+a+1);
		if(a%2==1) printf("1\n");
		else
		{
			long long int s = x[a/2 +1] - x[a/2]+1;
			long long int t = y[a/2 +1] - y[a/2]+1;
			printf("%lld\n",s*t);
		}
	}
}
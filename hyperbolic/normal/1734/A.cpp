#include <stdio.h>
#include <algorithm>


int x[1010];
int abs(int k)
{
	return k>0?k:-k;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		std::sort(x+1,x+a+1);
		
		int ans = 1234567890;
		for(int i=1;i+2<=a;i++)
		{
			int val = abs(x[i+1]-x[i]) + abs(x[i+2]-x[i+1]);
			ans = ans<val?ans:val;
		}
		printf("%d\n",ans);
	}
}
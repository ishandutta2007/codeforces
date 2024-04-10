#include <stdio.h>
#include <algorithm>

int x[110];
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
		
		int s = x[2] - x[1];
		for(int i=3;i<=a;i++) s = s < x[i]-x[i-1]? s: x[i]-x[i-1];
		printf("%d\n",s);
	}
}
#include <stdio.h>
#include <algorithm>

int x[10];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int count = 0;
		scanf("%d%d%d",&x[1],&x[2],&x[3]);
		std::sort(x+1,x+3);
		int a = x[3], b = x[2], c = x[1];
		if(a>=1) count++,a--;
		if(b>=1) count++,b--;
		if(c>=1) count++,c--;
		if(a>=1&&b>=1) count++,a--,b--;
		if(b>=1&&c>=1) count++,b--,c--;
		if(c>=1&&a>=1) count++,c--,a--;
		if(b>=1&&c>=1&&a>=1) count++;
		printf("%d\n",count);
	}
}
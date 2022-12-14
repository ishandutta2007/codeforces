#include <stdio.h>
#include <algorithm>

int x[200010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	std::sort(x+1,x+a+1);
	
	int p = a;
	int count = 1;
	for(int i=a-1;i>=1;i--)
	{
		while(x[p]>x[i]+b) p--;
		if(x[i]<x[p]);
		else count++;
	}
	printf("%d",count);
}
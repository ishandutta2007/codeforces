#include <stdio.h>
#include <algorithm>
int x[100010];
int main()
{
	int a,s=1;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	std::sort(x+1,x+a+1);
	for(int i=1;i<=a;i++)
	{
		if(x[i]>=s) s++;
	}
	printf("%d",s);
}
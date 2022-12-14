#include <stdio.h>
#include <algorithm>
int x[2010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=2*a;i++) scanf("%d",&x[i]);
	std::sort(x+1,x+2*a+1);
	if(x[a]==x[a+1])
	{
		printf("NO");
		return 0;
	}
	printf("YES");
}
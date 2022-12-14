#include <stdio.h>

int ans[200010],x[200010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	int p = 0;
	for(int i=1;i<=a;i++)
	{
		if(x[i]>=0) ans[i] = x[i] + ans[p], p = i;
		else ans[i] = x[i] + ans[p];
	}
	for(int i=1;i<=a;i++) printf("%d ",ans[i]);
}
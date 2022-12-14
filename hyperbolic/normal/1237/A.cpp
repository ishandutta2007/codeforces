#include <stdio.h>

int x[100010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	int count = 0;
	for(int i=1;i<=a;i++)
	{
		if(x[i]%2==0) printf("%d\n",x[i]/2);
		else
		{
			if(count%2==0) printf("%d\n",(x[i]+500)/2 - 250);
			else printf("%d\n",(x[i]+501)/2 - 250);
			count++;
		}
	}
}
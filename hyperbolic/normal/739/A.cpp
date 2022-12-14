#include <stdio.h>

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	int min = a+1;
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		min = min<d-c+1?min:d-c+1;
	}
	
	printf("%d\n",min);
	for(int i=0;i<a;i++) printf("%d ",i%min);
}
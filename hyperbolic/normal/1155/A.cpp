#include <stdio.h>

char x[300010];
int main()
{
	int a;
	scanf("%d",&a);
	scanf("%s",x+1);
	char c = x[1];
	int ind = 1;
	for(int i=2;i<=a;i++)
	{
		if(x[i]>c)
		{
			c = x[i];
			ind = i;
		}
		else if(x[i]<c)
		{
			printf("YES\n");
			printf("%d %d\n",ind,i);
			return 0;
		}
	}
	printf("NO");
}
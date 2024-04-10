#include <stdio.h>

int x[110];
int main()
{
	
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		if(a==3)
		{
			printf("3 2 1\n1 3 2\n3 1 2\n");
			continue;
		}
		
		for(int i=1;i<=a;i++) x[i] = a-i+1;
		for(int i=a+1;i<=2*a;i++) x[i] = x[i-a];
		for(int i=1;i<=a;i++)
		{
			for(int j=i;j<=a+i-1;j++) printf("%d ",x[j]);
			printf("\n");
		}
	}
}
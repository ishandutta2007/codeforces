#include <stdio.h>

int x[510][510];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) scanf("%d",&x[i][j]);
	for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) x[i][j] *= x[i][j];
	for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) x[i][j] *= x[i][j];
	
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			if((i+j)%2==0) printf("720720 ");
			else printf("%d ",720720-x[i][j]);
		}
		printf("\n");
	}
}
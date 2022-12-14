#include <stdio.h>

int check[510][510];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	if(a==1&&b==1) printf("0");
	else if(a==1) for(int i=1;i<=b;i++) printf("%d ",i+1);
	else if(b==1) for(int i=1;i<=a;i++) printf("%d ",i+1);
	else
	{
		for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) check[i][j] = 1;
		for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) check[i][j] *= i;
		for(int j=1;j<=b;j++) for(int i=1;i<=a;i++) check[i][j] *= (a+j);
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=b;j++) printf("%d ",check[i][j]);
			printf("\n");
		}
	}
}
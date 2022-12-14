#include <stdio.h>
char x[30];
int check[30];
int main()
{
	int a;
	scanf("%d",&a);
	scanf("%s",x+1);
	for(int i=1;i<=a;i++) check[x[i]-'0']=1;
	if(check[1]==1||check[2]==1||check[3]==1)
	{
		if(check[1]==1||check[4]==1||check[7]==1||check[0]==1)
		{
			if(check[3]==1||check[6]==1||check[9]==1||check[0]==1)
			{
				if(check[7]==1||check[0]==1||check[9]==1)
				{
					printf("YES");
					return 0;
				}
			}
		}
	}
	printf("NO");
}
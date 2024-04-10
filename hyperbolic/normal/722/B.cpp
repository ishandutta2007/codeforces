#include <stdio.h>
#include <string.h>

int x[110];
char y[110][110];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	scanf("\n");
	for(int i=1;i<=a;i++) fgets(y[i]+1,1000,stdin);
	for(int i=1;i<=a;i++)
	{
		int count = 0;
		int b = strlen(y[i]+1);
		for(int j=1;j<=b;j++)
		{
			if(y[i][j]=='a') count++;
			if(y[i][j]=='e') count++;
			if(y[i][j]=='i') count++;
			if(y[i][j]=='o') count++;
			if(y[i][j]=='u') count++;
			if(y[i][j]=='y') count++;
		}
		if(count!=x[i])
		{
			printf("NO");
			return 0;
		}
	}
	printf("YES");
}
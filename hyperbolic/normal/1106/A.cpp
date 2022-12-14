#include <stdio.h>

char x[510][510];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
	if(a<=2) printf("0");
	else
	{
		int ans = 0;
		for(int i=2;i<=a-1;i++)
		{
			for(int j=2;j<=a-1;j++)
			{
				int count = 0;
				if(x[i][j]=='X') count++;
				if(x[i-1][j-1]=='X') count++;
				if(x[i-1][j+1]=='X') count++;
				if(x[i+1][j-1]=='X') count++;
				if(x[i+1][j+1]=='X') count++;
				if(count==5) ans++;
			}
		}
		printf("%d",ans);
	}
}
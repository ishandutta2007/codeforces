#include <stdio.h>
#include <string.h>

char x[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int b;
		scanf("%s",x+1);
		int a = strlen(x+1);
		for(int i=a-1;i>=1;i--)
		{
			int b = (x[i]-'0') + (x[i+1]-'0');
			if(b>=10)
			{
				for(int j=1;j<=i-1;j++) printf("%c",x[j]);
				printf("%d",b);
				for(int j=i+2;j<=a;j++) printf("%c",x[j]);
				printf("\n");
				goto u;
			}
		}
		
		b = (x[1]-'0') + (x[2]-'0');
		printf("%d",b);
		for(int i=3;i<=a;i++) printf("%c",x[i]);
		printf("\n");
		u:;
	}
}
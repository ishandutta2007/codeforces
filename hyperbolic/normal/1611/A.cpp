#include <stdio.h>
#include <string.h.>

char x[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",x+1);
		int a = strlen(x+1);
		if((x[a]-'0')%2==0) printf("0\n");
		else if((x[1]-'0')%2==0) printf("1\n");
		else
		{
			int control = 0;
			for(int i=1;i<=a;i++) if((x[i]-'0')%2==0) control = 1;
			if(control==1) printf("2\n");
			else printf("-1\n");
		}
	}
}
#include <stdio.h>

char x[3][110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		scanf("%s%s",x[1]+1,x[2]+1);
		int control = 0;
		for(int j=1;j<=a;j++)
		{
			if(x[1][j]=='R'&x[2][j]!='R') control = 1;
			if(x[1][j]!='R'&x[2][j]=='R') control = 1;
		}
		if(control) printf("NO\n");
		else printf("YES\n");
	}
}
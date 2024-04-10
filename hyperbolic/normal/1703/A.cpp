#include <stdio.h>

char x[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",x+1);
		for(int i=1;i<=3;i++) if('a'<=x[i]&&x[i]<='z') x[i] += ('A'-'a');
		if(x[1]=='Y'&&x[2]=='E'&&x[3]=='S') printf("YES\n");
		else printf("NO\n");
	}
}
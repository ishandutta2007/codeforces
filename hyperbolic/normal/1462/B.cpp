#include <stdio.h>

char x[210];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		scanf("%s",x+1);
		if(x[1]=='2'&&x[2]=='0'&&x[3]=='2'&&x[4]=='0') printf("YES\n");
		else if(x[1]=='2'&&x[2]=='0'&&x[3]=='2'&&x[a]=='0') printf("YES\n");
		else if(x[1]=='2'&&x[2]=='0'&&x[a-1]=='2'&&x[a]=='0') printf("YES\n");
		else if(x[1]=='2'&&x[a-2]=='0'&&x[a-1]=='2'&&x[a]=='0') printf("YES\n");
		else if(x[a-3]=='2'&&x[a-2]=='0'&&x[a-1]=='2'&&x[a]=='0') printf("YES\n");
		else printf("NO\n");
	}
}
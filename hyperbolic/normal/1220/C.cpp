#include <stdio.h>
#include <string.h>

int check[500010],ans[500010];
char x[500010];
int main()
{
	scanf("%s",x+1);
	int a = strlen(x+1);
	for(int i=1;i<=a;i++)
	{
		int t = x[i]-'a';
		int control = 0;
		for(int j=0;j<t;j++) if(check[j]==1) control = 1;
		if(control==1) ans[i] = 1;
		else ans[i] = 0, check[t] = 1;
	}
	for(int i=1;i<=a;i++)
	{
		if(ans[i]==0) printf("Mike\n");
		else printf("Ann\n");
	}
}
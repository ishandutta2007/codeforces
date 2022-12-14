#include <stdio.h>
#include <string.h>
int check[30];
char x[1010],y[1010];
int main()
{
	check['a'-'a'] = 1;
	check['e'-'a'] = 1;
	check['i'-'a'] = 1;
	check['o'-'a'] = 1;
	check['u'-'a'] = 1;
	scanf("%s%s",x+1,y+1);
	int a = strlen(x+1);
	int b = strlen(y+1);
	if(a!=b) printf("No");
	else
	{
		for(int i=1;i<=a;i++)
		{
			if(check[x[i]-'a']-check[y[i]-'a']!=0)
			{
				printf("No");
				return 0;
			}
		}
		printf("Yes");
	}
}
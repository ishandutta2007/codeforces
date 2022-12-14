#include <stdio.h>

char x[110];
int check[110];
int main()
{
	check['a' - 'a'] = check['e' - 'a'] = check['i'-'a'] = check['o' - 'a'] = check['u' - 'a'] = check['y'-'a'] = 1;
	int a;
	scanf("%d",&a);
	scanf("%s",x+1);
	int count = 0;
	for(int i=1;i<=a;i++)
	{
		if(check[x[i]-'a']==1) count++;
		else count = 0;
		if(count<=1) printf("%c",x[i]);
		else count--;
	}
}
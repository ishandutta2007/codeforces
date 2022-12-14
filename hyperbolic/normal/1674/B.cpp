#include <stdio.h>

char x[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",x+1);
		int a = x[1]-'a', b = x[2]-'a';
		if(b<a) printf("%d\n",25*a+b+1);
		else printf("%d\n",25*a+b);
	}
}
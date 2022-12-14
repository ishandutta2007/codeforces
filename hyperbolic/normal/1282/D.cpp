#include <stdio.h>

int getQuery(int s, int t)
{
	for(int i=1;i<=s;i++) printf("a");
	for(int i=1;i<=t;i++) printf("b");
	printf("\n");
	fflush(stdout);
	
	int c;
	scanf("%d",&c);
	return c;
}

char x[310];
int main()
{
	int a = 300 - getQuery(300,0);
	if(a==300) return 0;
	int b = 300 - getQuery(0,300);
	if(b==300) return 0;
	
	int L = a+b;
	int c = a;
	for(int i=1;i<L;i++)
	{
		int d = getQuery(i,L-i);
		if(d==0) return 0;
		if(d>c) x[i] = 'b';
		else if(d<c) x[i] = 'a';
		c = d;
	}
	if(b>c) x[L] = 'b';
	else if(b<c) x[L] = 'a';
	
	for(int i=1;i<=L;i++) printf("%c",x[i]);
	printf("\n");
	fflush(stdout);
	
}
#include <stdio.h>

short check[101][101][10001];
short func(int a, int b, int c)
{
	if(a<1) return 0;
	if(b<1) return 0;
	if(c<0) return 0;
	if(check[a][b][c]!=-1) return check[a][b][c];
	short s1 = func(a-1,b,c-b);
	short s2 = func(a,b-1,c-a);
	return check[a][b][c] = 1-(1-s1)*(1-s2);
}

int main()
{
	for(int i=1;i<=100;i++) for(int j=1;j<=100;j++) for(int k=0;k<=10000;k++) check[i][j][k] = -1;
	
	check[1][1][0] = 1;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		printf("%s\n",func(a,b,c)?"YES":"NO");
	}
}
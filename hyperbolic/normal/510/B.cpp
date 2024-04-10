#include <stdio.h>
int dire1[10]={1,0,-1,0},dire2[10]={0,1,0,-1},control;
char x[60][60];
int check[60][60];
void func(int s, int t, int a, int b)
{
	int i;
	if(control) return;
	if(check[s][t])
	{
		control=1;
		return;
	}
	check[s][t]=1;
	for(i=0;i<4;i++)
	{
		if(s+dire1[i]==a&&t+dire2[i]==b) continue;
		if(x[s][t]==x[s+dire1[i]][t+dire2[i]]) func(s+dire1[i],t+dire2[i],s,t);
	}
}
int main()
{
	int a,b,i,j;
	scanf("%d%d",&a,&b);
	for(i=1;i<=a;i++) scanf("%s",x[i]+1);
	for(i=1;i<=a;i++)
	{
		for(j=1;j<=b;j++)
		{
			if(check[i][j]==0) func(i,j,0,0);
			if(control)
			{
				printf("Yes");
				return 0;
			}
		}
	}
	printf("No");
}
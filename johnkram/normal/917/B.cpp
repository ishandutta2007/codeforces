#include<bits/stdc++.h>
using namespace std;
int f[105][105][26],g[105][105],n,m,i,j;
char c[10];
int work(int x,int y,int z)
{
	if(~f[x][y][z])return f[x][y][z];
	int i;
	f[x][y][z]=0;
	for(i=1;i<=n;i++)if(g[x][i]>=z)f[x][y][z]|=!work(y,i,g[x][i]);
	return f[x][y][z];
}
int main()
{
	memset(f,-1,sizeof(f));
	memset(g,-1,sizeof(g));
	scanf("%d%d",&n,&m);
	while(m--)
	{
		scanf("%d%d%s",&i,&j,c);
		g[i][j]=c[0]-'a';
	}
	for(i=1;i<=n;i++,puts(""))for(j=1;j<=n;j++)putchar('B'-work(i,j,0));
	return 0;
}
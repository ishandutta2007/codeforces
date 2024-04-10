/****************************************************************
*	Author: huhao
*	Email: 826538400@qq.com
*	Create time: 2020-05-06 22:44:24
****************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#define fr(i,a,b) for(int i=(a),end_##i=(b);i<=end_##i;i++)
#define fd(i,a,b) for(int i=(a),end_##i=(b);i>=end_##i;i--)
int read()
{
	int r=0,t=1,c=getchar();
	while(c<'0'||c>'9')
	{
		t=c=='-'?-1:1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		r=(r<<3)+(r<<1)+(c^48);
		c=getchar();
	}
	return r*t;
}
const int N=1010;
int n,p[N][N],m,ans;
char c[N][N];
void dfs(int u,int v)
{
	if(p[u][v]||c[u][v]!='#') return ;
	p[u][v]=1; dfs(u+1,v); dfs(u,v-1); dfs(u,v+1); dfs(u-1,v);
}
int main()
{
	n=read(); m=read();
	fr(i,1,n) scanf("%s",c[i]+1);
	int p1=0,p2=0;
	fr(i,1,n)
	{
		int flag=0;
		fr(j,1,m) if(c[i][j]=='#')
		{
			if(flag){ printf("-1\n"); return 0; }
			if(c[i][j+1]!='#') flag=1;
		}
		if(!flag) p1=1;
	}
	fr(j,1,m)
	{
		int flag=0;
		fr(i,1,n) if(c[i][j]=='#')
		{
			if(flag){ printf("-1\n"); return 0; }
			if(c[i+1][j]!='#') flag=1;
		}
		if(!flag) p2=1;
	}
	if(p1^p2){ printf("-1\n"); return 0; }
	fr(i,1,n) fr(j,1,m) if(c[i][j]=='#'&&!p[i][j]){ ans++; dfs(i,j); }
	printf("%d\n",ans);
	return 0;
}
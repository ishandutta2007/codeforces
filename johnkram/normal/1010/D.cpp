#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000005
int n,i,j,ch[MAXN][2],a[MAXN][2],b[MAXN][2],ne[MAXN],w[MAXN],ans[MAXN];
char s[MAXN][4];
void merge(int x,int y,int l,int r)
{
	if(!l)return;
	if(!a[x][y])
	{
		a[x][y]=l;
		b[x][y]=r;
		return;
	}
	ne[b[x][y]]=l;
	b[x][y]=r;
}
void dfs(int x)
{
	if(s[x][0]=='I')
	{
		w[x]=ch[x][0];
		merge(x,!w[x],x,x);
		return;
	}
	int i,j;
	if(s[x][0]=='N')
	{
		dfs(ch[x][0]);
		w[x]=!w[ch[x][0]];
		for(i=0;i<2;i++)merge(x,i,a[ch[x][0]][!i],b[ch[x][0]][!i]);
		return;
	}
	for(i=0;i<2;i++)dfs(ch[x][i]);
	if(s[x][0]=='A')
	{
		w[x]=w[ch[x][0]]&&w[ch[x][1]];
		for(i=0;i<2;i++)for(j=0;j<2;j++)merge(x,j&&w[ch[x][!i]],a[ch[x][i]][j],b[ch[x][i]][j]);
		return;
	}
	if(s[x][0]=='O')
	{
		w[x]=w[ch[x][0]]||w[ch[x][1]];
		for(i=0;i<2;i++)for(j=0;j<2;j++)merge(x,j||w[ch[x][!i]],a[ch[x][i]][j],b[ch[x][i]][j]);
		return;
	}
	if(s[x][0]=='X')
	{
		w[x]=w[ch[x][0]]^w[ch[x][1]];
		for(i=0;i<2;i++)for(j=0;j<2;j++)merge(x,j^w[ch[x][!i]],a[ch[x][i]][j],b[ch[x][i]][j]);
		return;
	}
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%s%d",s[i],ch[i]);
		if(s[i][0]=='A'||s[i][0]=='O'||s[i][0]=='X')scanf("%d",ch[i]+1);
	}
	dfs(1);
	fill(ans+1,ans+n+1,-1);
	for(i=0;i<2;i++)for(j=a[1][i];j;j=ne[j])ans[j]=i;
	for(i=1;i<=n;i++)if(~ans[i])putchar(ans[i]^'0');
	return 0;
}
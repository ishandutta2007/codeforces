#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=551;
ll test,n,m,res;
ll f[MAXN][MAXN],g[MAXN][MAXN];
char ch[MAXN];
inline ll read()
{
    register ll num=0,neg=1;
    register char ch=getchar();
    while(!isdigit(ch)&&ch!='-')
    {
        ch=getchar();
    }
    if(ch=='-')
    {
        neg=-1;
        ch=getchar();
    }
    while(isdigit(ch))
    {
        num=(num<<3)+(num<<1)+(ch-'0');
        ch=getchar();
    }
    return num*neg;
}
inline void solve()
{
	n=read(),m=read(),res=0;
	for(register int i=1;i<=n;i++)
	{
		scanf("%s",ch+1);
		for(register int j=1;j<=m;j++)
		{
			res+=(f[i][j]=ch[j]=='*');
		}
	}
	for(register int k=2;k<=(m+5)>>1;k++)
	{
		for(register int i=1;i<=n;i++)
		{
			for(register int j=1;j<=m;j++)
			{
				g[i][j]=f[i][j-1]&f[i][j+1]&f[i-1][j]&f[i][j];
			}
		}
		for(register int i=1;i<=n;i++)
		{
			for(register int j=1;j<=m;j++)
			{
				res+=(f[i][j]=g[i][j]);
			}
		}
	}
	printf("%d\n",res);
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}
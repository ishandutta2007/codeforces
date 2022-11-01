#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=1e6+51;
ll test,n,m,r1,r2;
ll col[MAXN],f[MAXN],g[MAXN],h[MAXN];
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
	n=read(),m=read();
	for(register int i=1;i<=n;i++)
	{
		scanf("%s",ch+1);
		for(register int j=1;j<=m;j++)
		{
			col[(i-1)*m+j]=!(ch[j]&1);
		}
	}
	for(register int i=1;i<=n;i++)
	{
		scanf("%s",ch+1);
		for(register int j=1;j<=m;j++)
		{
			ch[j]=='U'?f[(i-1)*m+j]=(i-2)*m+j:1;
			ch[j]=='D'?f[(i-1)*m+j]=i*m+j:1;
			ch[j]=='L'?f[(i-1)*m+j]=(i-1)*m+j-1:1;
			ch[j]=='R'?f[(i-1)*m+j]=(i-1)*m+j+1:1;
		}
	}
	n*=m,r1=r2=0;
	for(register int i=1;i<=23;i++)
	{
		for(register int j=1;j<=n;j++)
		{
			g[j]=f[f[j]];
		}
		for(register int j=1;j<=n;j++)
		{
			f[j]=g[j];
		}
	}
	for(register int i=1;i<=n;i++)
	{
		g[i]=h[i]=0;
	}
	for(register int i=1;i<=n;i++)
	{
		g[f[i]]++,h[f[i]]+=col[i];
	}
	for(register int i=1;i<=n;i++)
	{
		r1+=!!g[i],r2+=!!h[i];
	}
	printf("%d %d\n",r1,r2);
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}
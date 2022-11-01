#include<bits/stdc++.h>
using namespace std;
typedef int ll; 
typedef long long int li;
const ll MAXN=151;
ll test,n,m,syk;
char ch[MAXN][MAXN];
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
	n=read(),m=read(),syk=0;
	for(register int i=1;i<=n;i++)
	{
		scanf("%s",ch[i]+1);
	}
	for(register int i=1;i<=n;i++)
	{
		syk+=(ch[i][m]=='R');
	}
	for(register int i=1;i<=m;i++)
	{
		syk+=(ch[n][i]=='D');
	}
	printf("%d\n",syk);
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}
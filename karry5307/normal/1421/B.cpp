#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e3+51;
ll test,n;
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
	n=read();
	for(register int i=1;i<=n;i++)
	{
		scanf("%s",ch[i]+1);
	}
	if(ch[1][2]==ch[2][1])
	{
		if(ch[n-1][n]==ch[n][n-1])
		{
			if(ch[1][2]!=ch[n-1][n])
			{
				return (void)puts("0");
			}
			return (void)puts("2\n1 2\n2 1");
		}
		if(ch[n-1][n]==ch[1][2])
		{
			return (void)printf("1\n%d %d\n",n-1,n);
		}
		return (void)printf("1\n%d %d\n",n,n-1);
	}
	if(ch[n-1][n]==ch[n][n-1])
	{
		if(ch[1][2]==ch[n-1][n])
		{
			return (void)puts("1\n1 2");
		}
		return (void)puts("1\n2 1");
	}
	if(ch[1][2]==ch[n-1][n])
	{
		return (void)printf("2\n1 2\n%d %d\n",n,n-1);
	}
	return (void)printf("2\n1 2\n%d %d\n",n-1,n);
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}
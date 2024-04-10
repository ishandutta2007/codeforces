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
	for(register int i=1;i<=n-1;i++)
	{
		for(register int j=1;j<=n-1;j++)
		{ 
			if(ch[i][j]=='1'&&ch[i+1][j]!='1'&&ch[i][j+1]!='1')
			{
				return (void)puts("No");
			}
		}
	}
	puts("Yes");
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}
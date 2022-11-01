#include<bits/stdc++.h>
using namespace std;
typedef int ll; 
typedef long long int li;
const ll MAXN=3e5+51;
ll test,n,kk,syk,ak;
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
	n=read(),kk=read(),scanf("%s",ch+1);
	for(register int i=1;i<=kk;i++)
	{
		syk=-1;
		for(register int j=i;j<=n;j+=kk)
		{
			if(ch[j]=='?')
			{
				continue;
			}
			syk==-1?syk=ch[j]:1;
			if(syk!=ch[j])
			{
				return (void)puts("NO");
			}
		}
		if(syk!=-1)
		{
			for(register int j=i;j<=n;j+=kk)
			{
				ch[j]=syk;
			}
		}
	}
	syk=ak=0;
	for(register int i=1;i<=kk;i++)
	{
		ch[i]!='?'?ch[i]&1?syk++:ak++:1;
	}
	puts(syk<=kk/2&&ak<=kk/2?"YES":"NO");
} 
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}
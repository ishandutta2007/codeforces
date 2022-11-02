#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll test,n,d,x;
ll f[151];
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
	n=read(),d=read(),memset(f,0,sizeof(f)),f[0]=1;
	for(register int i=1;i<=d*10;i++)
	{
		for(register int j=0;j<=d;j++)
		{
			i>=j*10+d?f[i]|=f[i-j*10-d]:1;
		}
	}
	for(register int i=1;i<=n;i++)
	{
		x=read(),puts(x>=10*d||f[x]?"Yes":"No");
	}
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}
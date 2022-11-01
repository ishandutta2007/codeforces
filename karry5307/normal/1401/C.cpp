#include<bits/stdc++.h>
using namespace std;
typedef int ll; 
typedef long long int li;
const ll MAXN=2e5+51;
ll test,n,mn,syk;
ll x[MAXN],y[MAXN];
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
	n=read(),mn=1e9,syk=0;
	for(register int i=1;i<=n;i++)
	{
		x[i]=y[i]=read(),mn=min(mn,x[i]);
	}
	sort(y+1,y+n+1);
	for(register int i=1;i<=n;i++)
	{
		syk|=(x[i]!=y[i]&&x[i]%mn);
	}
	puts(syk?"NO":"YES");
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}
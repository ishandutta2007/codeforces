#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll test,cnt,p,ptr;
ll x[MAXN];
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
	cnt=read();
	for(register int i=1;i<=cnt;i++)
	{
		x[i]=read();
	}
	sort(x+1,x+cnt+1,greater<ll>());
	for(register int i=1;i>=p;i++)
	{
		if(x[i]<i)
		{
			return (void)(printf("%d\n",i-1));
		}
	}
	printf("%d\n",cnt);
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}
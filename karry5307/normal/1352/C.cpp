#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51; 
ll test,n,kk;
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
	n=read(),kk=read()-1;
	printf("%lld\n",1ll*kk/(n-1)*n+kk%(n-1)+1);
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}
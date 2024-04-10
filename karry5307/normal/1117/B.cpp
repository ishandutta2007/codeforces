#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e5+51;
ll n,m,kk,u,v;
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
int main()
{
	n=read(),m=read(),kk=read(),u=m-m/(kk+1),v=m-u;
	for(register int i=1;i<=n;i++)
	{
		x[i]=read();
	}
	sort(x+1,x+n+1),printf("%lld\n",u*x[n]+v*x[n-1]);
}
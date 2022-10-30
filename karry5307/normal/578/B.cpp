#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e5+51;
ll n,kk,c,pw,res;
ll x[MAXN],prefix[MAXN],suffix[MAXN];
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
	n=read(),kk=read(),c=read(),pw=1;
	for(register int i=1;i<=kk;i++)
	{
		pw*=c;
	}
	for(register int i=1;i<=n;i++)
	{
		x[i]=read(),prefix[i]=prefix[i-1]|x[i];
	}
	for(register int i=n;i;i--)
	{
		suffix[i]=suffix[i+1]|x[i];
		res=max(res,prefix[i-1]|(x[i]*pw)|suffix[i+1]);
	}
	printf("%lld\n",res);
}
#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51,inf=0x3f3f3f3f;
ll n,h,c,res,rr;
ll l[MAXN],r[MAXN],prefix[MAXN];
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
	n=read(),l[n+1]=r[n+1]=inf,h=read();
	for(register int i=1;i<=n;i++)
	{
		l[i]=read(),r[i]=read();
	}
	for(register int i=2;i<=n+1;i++)
	{
		prefix[i]=prefix[i-1]+l[i]-r[i-1];
	}
	for(register int i=1;i<=n;i++)
	{
		c=lower_bound(prefix+1,prefix+n+2,h+prefix[i])-prefix;
		rr=h-prefix[c-1]+prefix[i],res=max(res,r[c-1]+rr-l[i]);
	}
	printf("%d\n",res);
}
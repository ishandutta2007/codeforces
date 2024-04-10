#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e5+51;
ll n,x,syk,ccc;
ll c[MAXN],mx[MAXN];
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
	n=read();
	for(register int i=1;i<=n;i++)
	{
		c[i]=read();
		for(register int j=1;j<=c[i];j++)
		{
			x=read(),mx[i]=max(mx[i],x);
		}
		ccc=max(ccc,mx[i]);
	}
	for(register int i=1;i<=n;i++)
	{
		syk+=c[i]*(ccc-mx[i]);
	}
	printf("%lld\n",syk);
}
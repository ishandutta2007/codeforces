#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll n,res,syk=0x3f3f3f3f;
ll x[MAXN],c[MAXN];
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
		x[i]=read(),c[i]=(x[i]-i+n)/n;
	}
	for(register int i=1;i<=n;i++)
	{
		c[i]<syk?syk=c[i],res=i:1;
	}
	printf("%d\n",res);
}
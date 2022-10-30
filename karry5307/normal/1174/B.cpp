#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll n;
ll x[MAXN],c[2];
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
		c[(x[i]=read())&1]++;
	}
	c[0]&&c[0]!=n?sort(x+1,x+n+1):(void)1;
	for(register int i=1;i<=n;i++)
	{
		printf("%d ",x[i]);
	}
}
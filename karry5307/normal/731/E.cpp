#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e5+51;
ll n,r;
ll prefix[MAXN],f[MAXN];
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
		prefix[i]=prefix[i-1]+read();
	}
	r=prefix[n];
	for(register int i=n-1;i>=1;i--)
	{
		f[i]=r,r=max(r,prefix[i]-f[i]);
	}
	printf("%lld\n",f[1]);
}
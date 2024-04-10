#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e5+51;
ll n;
ll x[MAXN],prefix[MAXN],f[MAXN],g[MAXN];
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
	n=read(),memset(f,0x3f,sizeof(f)),memset(g,0x3f,sizeof(g)),f[0]=g[0]=0;
	for(register int i=1;i<=n;i++)
	{
		x[i]=read(),prefix[i]=prefix[i-1]+x[i];
	}
	for(register int i=1;i<=n;i++)
	{
		for(register int j=1;j<=i;j++)
		{
			if(prefix[i]-prefix[j-1]>=g[j-1]&&i-j+f[j-1]<=f[i])
			{
				f[i]=i-j+f[j-1],g[i]=prefix[i]-prefix[j-1];
			}
		}
	}
	printf("%d\n",f[n]);
}
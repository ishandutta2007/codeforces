#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51,MOD=1e9+7;
vector<ll>v;
ll n,res;
ll f[MAXN*5],x[MAXN];
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
	n=read(),f[0]=1;
	for(register int i=1;i<=n;i++)
	{
		x[i]=read();
	}
	for(register int i=1;i<=n;i++)
	{
		v.clear();
		for(register int j=1;j<=sqrt(x[i])&&j<=n;j++)	
		{
			if(x[i]%j==0)
			{
				v.push_back(j);
				j*j!=x[i]&&x[i]/j<=n?v.push_back(x[i]/j):(void)1;
			}
		}
		sort(v.begin(),v.end(),greater<ll>());
		for(register int i:v)
		{
			f[i]=(f[i]+f[i-1])%MOD;
		}
	}
	for(register int i=1;i<=n;i++)
	{
		res=(res+f[i])%MOD;
	}
	printf("%d\n",res);
}
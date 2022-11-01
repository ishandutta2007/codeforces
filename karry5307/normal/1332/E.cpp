#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MOD=998244353;
ll n,l,r,odd,even;
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
inline ll qpow(ll base,ll exponent)
{
	ll res=1;
	while(exponent)
	{
		if(exponent&1)
		{
			res=res*base%MOD;
		}
		base=base*base%MOD,exponent>>=1;
	}
	return res;
}
int main()
{
	n=read(),n*=read(),l=read(),r=read();
	if(n&1)
	{
		return printf("%lld\n",qpow(r-l+1,n)),0;
	}
	odd=((r-l)/2+((l&1)||(r&1)?1:0)),even=r-l+1-odd;
	printf("%lld\n",((qpow(odd+even,n)+qpow(odd-even+MOD,n))%MOD)*499122177%MOD);
}
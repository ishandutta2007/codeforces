#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e5+51,MOD=1e9+7,INV2=5e8+4;
ll n,kk,res,r;
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
	kk=read(),n=read(),n>kk?r=(n-kk)%MOD*(kk%MOD)%MOD,n=kk:1;
	for(register ll l=1,r;l<=n;l=r+1)
	{
		r=min(kk/(kk/l),n);
		res=(res+(l+r)%MOD*((r-l+1)%MOD)%MOD*INV2%MOD*((kk/l)%MOD)%MOD)%MOD;
	}
	printf("%lld\n",((n%MOD)*(kk%MOD)%MOD-res+MOD+r+MOD)%MOD);
}
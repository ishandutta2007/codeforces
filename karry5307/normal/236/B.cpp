#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51,MOD=1073747824;
ll x,y,z,res;
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
inline ll calcD(ll x)
{
	li res=1,exponent;
	for(register int i=2;i<=sqrt(x);i++)
	{
		if(!(x%i))
		{
			exponent=1,x/=i;
			while(!(x%i))
			{
				exponent++,x/=i;
			}
			res=(li)res*(exponent+1)%MOD;
		}
	}
	if(x!=1)
	{
		res=(li)res*2%MOD;
	}
	return res;
}
int main()
{
	x=read(),y=read(),z=read();
	for(register int i=1;i<=x;i++)
	{
		for(register int j=1;j<=y;j++)
		{
			for(register int k=1;k<=z;k++)
			{
				res=(res+calcD(i*j*k))%MOD;
			}
		}
	}
	printf("%d\n",res);
}
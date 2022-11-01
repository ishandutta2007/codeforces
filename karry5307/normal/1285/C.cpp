#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=1;
ll x,res,ress,r1,r2;
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
	x=read();
	for(register ll i=1;i<=sqrt(x);i++)
	{
		if(x%i==0)
		{
			if(__gcd(i,x/i)==1)
			{
				res=i,ress=x/i;
			}
		}
	}
	printf("%lld %lld\n",res,ress);
}
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e5+51;
ll h,n,res,d,d2;
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
	h=read(),n=read(),res=(1ll<<h+1)-1,d=1;
	for(register int i=h-1;i>=0;i--)
	{
		1ll<<i>=n?d2=-1:(n-=(1ll<<i),d2=1),d!=d2?res-=(1ll<<i+1)-1:1,d=d2;
	}
	printf("%lld\n",res-1);
}
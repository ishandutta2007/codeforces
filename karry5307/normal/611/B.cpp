#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e5+51;
ll l,r,res;
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
	l=read(),r=read();
	for(register int i=2;i<=63;i++)
	{
		for(register int j=0;j<i-1;j++)
		{
			res+=(l<=((1ll<<i)-1-(1ll<<j)))&&(((1ll<<i)-1-(1ll<<j))<=r);
		}
	}	
	printf("%lld\n",res);
}
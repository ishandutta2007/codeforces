#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e5+51;
map<ll,ll>mp;
ll n,res,prefix;
ll x[MAXN];
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
	n=read(),mp[0]=1;
	for(register int i=1;i<=n;i++)
	{
		x[i]=read();
	}	
	for(register int i=1;i<=n;i++)
	{
		prefix+=x[i];
		if(mp[prefix])
		{
			res++,mp.clear(),prefix=x[i],mp[0]=1;	
		}	
		mp[prefix]=1;
	}
	printf("%lld\n",res);
}
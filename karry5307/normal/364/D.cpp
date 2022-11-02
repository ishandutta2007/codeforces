#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef map<ll,ll>::iterator iter;
const ll MAXN=1e6+51;
mt19937 mt(20060202*20060202);
map<ll,ll>mp;
ll n,c,xgzc,res,r;
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
	n=read();
	for(register int i=1;i<=n;i++)
	{
		x[i]=read();
	}
	for(register int i=1;i<=10;i++)
	{
		c=mt()%n+1,mp.clear();
		for(register int j=1;j<=n;j++)
		{
			xgzc=__gcd(x[c],x[j]),mp[xgzc]++;	
		}
		for(register iter it=mp.end();it!=mp.begin();)
		{
			if((*--it).first<=res)
			{
				continue;
			}
			r=0;
			for(register iter it2=it;it2!=mp.end()&&r*2<n;++it2)
			{
				!((*it2).first%(*it).first)?r+=(*it2).second:1;
			}
			r*2>=n?res=(*it).first:1;
		}
	}
	printf("%lld\n",res);
}
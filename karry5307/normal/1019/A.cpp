#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll n,m,p,c;
li res=1e18;
vector<ll>v[MAXN];
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
inline li calc(ll x)
{
	li res=0,cur=0,c=v[1].size();
	vector<ll>r;
	for(register int i=2;i<=m;i++)
	{
		if((cur=v[i].size())>=x)
		{
			for(register int j:v[i])
			{
				cur>=x?res+=j,cur--,c++:(r.push_back(j),1);
			}
			continue;
		}
		for(register int j:v[i])
		{
			r.push_back(j);
		}
	}
	sort(r.begin(),r.end(),greater<ll>());
	while(c<x)
	{
		res+=r.back(),r.pop_back(),c++;
	}
	return res;
}
int main()
{
	n=read(),m=read();
	for(register int i=1;i<=n;i++)
	{
		p=read(),c=read(),v[p].push_back(c);
	}
	for(register int i=1;i<=m;i++)
	{
		sort(v[i].begin(),v[i].end());
	}
	for(register int i=1;i<=n;i++)
	{
		res=min(res,calc(i));
	}
	printf("%lld\n",res);
}
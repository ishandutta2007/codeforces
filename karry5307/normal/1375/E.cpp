#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
typedef pair<ll,ll> pii;
const ll MAXN=2e5+51;
vector<pii>v;
ll n;
pii x[MAXN];
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
		x[i]={read(),i};
	}
	for(register int i=1;i<=n;i++)
	{
		for(register int j=i;j;j--)
		{
			if(x[j-1].first>x[j].first)
			{
				v.push_back({x[j-1].second,x[j].second}),swap(x[j-1],x[j]);
			}
		}
	}
	reverse(v.begin(),v.end()),printf("%d\n",v.size());
	for(register pii i:v)
	{
		printf("%d %d\n",i.first,i.second);
	}
}
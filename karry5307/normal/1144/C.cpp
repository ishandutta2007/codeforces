#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
unordered_map<ll,ll>mp;
ll n;
vector<ll>v1,v2;
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
		mp[read()]++;
	}
	for(auto i:mp)
	{
		if(i.second>2)
		{
			return puts("NO"),0;
		}
		v1.push_back(i.first),i.second-1?v2.push_back(i.first):(void)1;
	}
	sort(v1.begin(),v1.end()),sort(v2.begin(),v2.end(),greater<ll>());
	puts("YES"),printf("%d\n",v1.size());
	for(register int i:v1)
	{
		printf("%d ",i);
	}
	printf("\n%d\n",v2.size());
	for(register int i:v2)
	{
		printf("%d ",i);
	}
}
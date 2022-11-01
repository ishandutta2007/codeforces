#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
vector<ll>rr,cur;
unordered_map<ll,ll>mp;
ll n,kk,l,r,mid,res;
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
inline ll check(ll mid)
{
	cur.clear();
	for(auto i:mp)
	{
		for(register int j=1;j<=i.second/mid;j++)
		{
			cur.push_back(i.first);
		}
	}
	return cur.size()>=kk?rr=cur,1:0;
}
int main()
{
	n=read(),kk=read(),l=1,r=200000;
	for(register int i=1;i<=n;i++)
	{
		mp[read()]++;
	}
	while(l<=r)
	{
		mid=(l+r)>>1;
		check(mid)?res=mid,l=mid+1:r=mid-1;
	}
	for(register int i=0;i<kk;i++)
	{
		printf("%d ",rr[i]);
	}
}
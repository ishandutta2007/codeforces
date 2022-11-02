#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
typedef pair<ll,ll>pii;
const ll MAXN=2e5+51;
vector<ll>r;
vector<pii>res;
unordered_map<ll,ll>mp;
ll test,n,c;
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
inline void solve()
{
	c=n=read(),mp.clear(),r.clear(),res.clear();
	while(c!=2)
	{
		mp[c]=1,r.push_back(c),c=ceil(sqrt(1.0*c));
	}
	r.push_back(2);
	for(register int i=3;i<n;i++)
	{
		!mp[i]?res.push_back((pii){i,n}):(void)1;
	}
	for(register int i=0;i<r.size()-1;i++)
	{
		res.push_back((pii){r[i],r[i+1]}),res.push_back((pii){r[i],r[i+1]});
	}
	printf("%d\n",res.size());
	for(auto i:res)
	{
		printf("%d %d\n",i.first,i.second);
	}
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}
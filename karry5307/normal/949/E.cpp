#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
vector<ll>res,c;
ll n;
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
inline vector<ll> dfs(ll cur)
{
	if(cur>19)
	{
		return vector<ll>();
	}
	ll flg=1;
	for(register int i:c)
	{
		if(i&1)
		{
			flg=0;
			break;
		}
	}
	if(flg)
	{
		for(register int &i:c)
		{
			i>>=1;
		}
		sort(c.begin(),c.end()),c.erase(unique(c.begin(),c.end()),c.end());
		return dfs(cur+1);
	}
	vector<ll>cc=c,rl,rr;
	for(register int &i:c)
	{
		i=(i+1)>>1;
	}
	sort(c.begin(),c.end()),c.erase(unique(c.begin(),c.end()),c.end());
	rl=dfs(cur+1),c=cc;
	for(register int &i:c)
	{
		i>>=1;
	}
	sort(c.begin(),c.end()),c.erase(unique(c.begin(),c.end()),c.end());
	rr=dfs(cur+1),rl.push_back(-(1<<cur)),rr.push_back(1<<cur);
	return rl.size()<rr.size()?rl:rr;
}
int main()
{
	n=read();
	for(register int i=1;i<=n;i++)
	{
		c.push_back(read());
	}
	printf("%d\n",(res=dfs(0)).size());
	for(register int i:res)
	{
		printf("%d ",i);
	}
}
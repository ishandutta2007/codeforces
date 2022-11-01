#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
typedef pair<ll,ll> pii;
const ll MAXN=2e5+51;
vector<pii>g[MAXN];
vector<ll>res[MAXN];
ll n,m,len,p,tot,zkdxl,rr,cnt;
ll x[MAXN],y[MAXN],z[MAXN],vis[MAXN];
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
inline void dfs(ll x)
{
	pii bk;
	vis[x]=1;
	while(!g[x].empty())
	{
		bk=g[x].back(),g[x].pop_back();
		dfs(bk.first),res[tot].push_back(bk.second);
	}
}
int main()
{
	n=read(),m=read();
	for(register int i=1;i<=n;i++)
	{
		x[i]=y[i]=read();
	}
	sort(y+1,y+n+1);
	for(register int i=1;i<=n;i++)
	{
		z[i]=(len+=(y[i]!=y[i-1]));
	}
	len=unique(y+1,y+n+1)-y-1;
	for(register int i=1;i<=n;i++)
	{
		x[i]=lower_bound(y+1,y+len+1,x[i])-y;
	}
	for(register int i=1;i<=n;i++)
	{
		if(x[i]!=z[i])
		{
			g[x[i]].push_back(make_pair(z[i],i)),p++;
		}
	}
	if(p>m)
	{
		return puts("-1"),0;
	}
	if(!p)
	{
		return puts("0"),0;
	}
	for(register int i=1;i<=len;i++)
	{
		if(!vis[i]&&!g[i].empty())
		{
			tot++,dfs(i);
		}
	}
	if(tot<=1||m-p<=1)
	{
		printf("%d\n",tot);
		for(register int i=1;i<=tot;i++)
		{
			printf("%d\n",res[i].size());
			for(register int j:res[i])
			{
				printf("%d ",j);
			}
			puts("");
		}
		return 0;
	}
	rr=min(m-p,tot),printf("%d\n%d\n",zkdxl=tot+2-rr,rr);
	for(register int i=1;i<=rr;i++)
	{
		printf("%d%c",res[i].back()," \n"[i==rr]),cnt+=res[i].size();
	}
	reverse(res+1,res+rr+1),printf("%d\n",cnt);
	for(register int i=1;i<=rr;i++)
	{
		for(register int j:res[i])
		{
			printf("%d ",j);
		}
	}
	puts("");
	for(register int i=rr+1;i<=tot;i++)
	{
		printf("%d\n",res[i].size());
		for(register int j:res[i])
		{
			printf("%d ",j);
		}
		puts("");
	}
}
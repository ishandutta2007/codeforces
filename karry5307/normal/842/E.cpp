#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=3e5+51;
vector<ll>s,t;
ll n,ds,dt,mxd;
ll depth[MAXN],anc[MAXN][20];
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
inline void add(ll x,ll fa)
{
	depth[x]=depth[anc[x][0]=fa]+1;
	for(register int i=1;i<=19;i++)
	{
		anc[x][i]=anc[anc[x][i-1]][i-1];
	}
}
inline ll LCA(ll x,ll y)
{
	depth[x]<depth[y]?swap(x,y):(void)1;
	for(register int i=19;i>=0;i--)
	{
		depth[anc[x][i]]>=depth[y]?x=anc[x][i]:1;
	}
	for(register int i=19;i>=0;i--)
	{
		anc[x][i]!=anc[y][i]?x=anc[x][i],y=anc[y][i]:1;
	}
	return x==y?x:anc[x][0];
}
inline ll dist(ll x,ll y)
{
	return depth[x]+depth[y]-2*depth[LCA(x,y)];
}
int main()
{
	n=read(),add(1,0),s.push_back(1);
	for(register int i=2;i<=n+1;i++)
	{
		add(i,read()),ds=s.empty()?0:dist(i,s[0]),dt=t.empty()?0:dist(i,t[0]);
		if(max(ds,dt)>mxd)
		{
			if(ds>mxd)
			{
				mxd=ds;
				for(register int j:t)
				{
					dist(i,j)==mxd?s.push_back(j):(void)1;
				}
				t.clear(),t.push_back(i);
			}
			if(dt>mxd)
			{
				mxd=dt;
				for(register int j:s)
				{
					dist(i,j)==mxd?t.push_back(j):(void)1;
				}
				s.clear(),s.push_back(i);
			}
		}
		else
		{
			if(max(ds,dt)==mxd)
			{
				ds==mxd?t.push_back(i):dt==mxd?s.push_back(i):(void)1;	
			}
		}
		mxd=max(mxd,max(ds,dt)),printf("%d\n",s.size()+t.size());
	}
}
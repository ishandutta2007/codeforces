#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,u) for(int i=start[u];i;i=e[i].next)
#define fi first
#define se second
#define mkr(a,b) make_pair(a,b)
#define SZ(A) ((int)A.size())
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
inline int read()
{
	int s=0,f=1; char ch=getchar();
	while(!isdigit(ch) && ch!='-')ch=getchar();
	if(ch=='-')ch=getchar(),f=-1;
	while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
	return ~f?s:-s;
}
 
const ll maxn=2e6+20;
 
ll c[maxn];
int n,m,in[maxn];
vector<int>ed[maxn];
int tot;
set<int>s[maxn];
int vis[maxn],id[maxn];
int Vis[maxn],Tim,ID[maxn];
 
inline void init()
{
	n=read();m=read();
	REP(i,1,n)scanf("%lld",c+i),ed[i].clear(),in[i]=0;
	   REP(i,1,tot)Vis[i]=ID[i]=vis[i]=0;
	REP(i,1,tot)s[i].clear(); tot=0;
	REP(i,1,m)
	{
		int u=read(),v=read();
		ed[u].push_back(v);in[v]++;
	}
	tot=1;
	REP(i,1,n)s[1].insert(i),id[i]=1,Vis[i]=0,ID[i]=0,vis[i]=0;
	Tim=0;
	REP(i,1,n)
	{
		++Tim;
		for(int j:ed[i])
		{
			int x=id[j];
			s[x].erase(j);
			vis[j]=x;
		}
		for(int j:ed[i])
		{
			if(Vis[vis[j]]==Tim)
			{
				
			}else Vis[vis[j]]=Tim,ID[vis[j]]=++tot;
			id[j]=ID[vis[j]];
			s[ID[vis[j]]].insert(j);
		}
	}
}
 
inline void doing()
{
	ll ans=0;
	REP(i,1,tot)if(!s[i].empty())
	{
		ll sum=0;
		for(ll x:s[i])sum+=c[x];//,cerr<<x<<" ";
		//cerr<<sum<<endl;
		if(in[*s[i].begin()])ans=__gcd(ans,sum);
	}
	printf("%lld\n",ans);
}
 
int main()
{
#ifndef ONLINE_JUDGE
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
#endif
	int t=read();
	while(t--)
	{
		init();
		doing();
	}
	return 0;
}
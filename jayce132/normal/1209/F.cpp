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

const int maxn=1e6+20;
const int mod=1e9+7;

int n,m,tot;
int val[maxn];

#define pii pair<int,int>

vector<int >ed[maxn][10];
int dis[maxn],vis[maxn];

inline void link(int u,int v,int x)
{
	vector<int>val,id;
	id.push_back(u);
	while(x)
	{
		val.push_back(x%10);
		x/=10;
	}
	reverse(val.begin(),val.end());
	REP(i,0,SZ(val)-2)id.push_back(++tot);
	id.push_back(v);
	REP(i,0,SZ(val)-1)
	{
		ed[id[i]][val[i]].push_back(id[i+1]);
	}
}

inline void init()
{
	n=read();m=read();
	tot=n;
	REP(i,1,m)
	{
		int u=read(),v=read();
		link(u,v,i);
		link(v,u,i);
	}
}

inline void bfs(int S)
{
	dis[S]=0; vis[S]=1; queue<vector<int> >q;
	q.push({S});
	while(!q.empty())
	{
		//int u=q.front();q.pop();vis[u]=1;
		vector<int>now=q.front(); q.pop();
		REP(j,0,9)
		{
			vector<int>t;
			for(int u:now)
			{
				int dt=((ll)dis[u]*10+j)%mod;
				for(int v:ed[u][j])
				{
					if(!vis[v])
					{
						dis[v]=dt;
						t.push_back(v);
						vis[v]=1;
					}
				}
			}
			if(!t.empty())q.push(t);
		}
	}
}

inline void doing()
{
	bfs(1);
	REP(i,2,n)printf("%d\n",dis[i]);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}
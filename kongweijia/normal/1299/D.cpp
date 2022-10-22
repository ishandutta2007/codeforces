#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 100000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

vector<pii> e[maxn+5];
int vis[maxn+5],status,cyc;
vi vec;

vi p[400];
int b[maxn+5][3];
int st[maxn+5],val[maxn+5];
int sv[400][400];
int dp[2][400];

void add(int &x,int y) {x=x+y<mod?x+y:x+y-mod;}

bool upd(vi &b,int x)
{
	per(i,0,4) if((x>>i)&1)
	{
		if(b[i]==0)
		{
			b[i]=x;
			rep(j,0,i-1) if((b[i]>>j)&1) b[i]^=b[j];
			per(j,i+1,4) if((b[j]>>i)&1) b[j]^=b[i];
			return 0;
		}
		x^=b[i];
	}
	return 1;
}

vi mrg(vi b,vi c)
{
	for(auto x: c) if(x) 
	{
		if(upd(b,x))
		{
			b[0]=-1;
			return b;
		}
	}
	return b;
}

void dfs(int now,int fa,int x)
{
	if(vis[now])
	{
		if(now==1)
		{
			if(status==1) status=2;
			cyc=x;
		}
		else
		{
			if(upd(vec,x^val[now])) status=0;
		}
		return;	
	}
	vis[now]=vis[fa]+1;
	val[now]=x;
	for(auto it: e[now]) if(it.FI!=fa)
	{
		if(vis[it.FI]>vis[now]) continue;
		dfs(it.FI,now,x^it.SE);
	}
}

int main()
{
	map<vi,int> id;
	int tot=0;
	vi dummy(5,0); id[dummy]=++tot; p[tot]=dummy;
	rep(front,1,tot)
	{
		rep(i,0,31)
		{
			vi tmp=p[front];
			if(upd(tmp,i)==0 && id.find(tmp)==id.end())
			{
				id[tmp]=++tot;
				p[tot]=tmp;
			}
		}
	}
	rep(i,1,tot) rep(j,1,tot)
	{
		vi res=mrg(p[i],p[j]);
		if(res[0]==-1) sv[i][j]=-1;
		else sv[i][j]=id[res];
	}

	int n,m; scanf("%d%d",&n,&m);
	rep(i,1,m)
	{
		int w,u,v; scanf("%d%d%d",&u,&v,&w);
		e[u].pb(mp(v,w));
		e[v].pb(mp(u,w));
	}
	int N=0;
	vis[1]=1;
	for(auto it: e[1]) if(vis[it.FI]==0)
	{
		vec.clear(); vec.resize(5,0); status=1;
		dfs(it.FI,1,it.SE);
		if(status)
		{
			N++;
			b[N][0]=id[vec];
			if(status==2)
			{
				st[N]=1;
				b[N][1]=id[vec];
				if(upd(vec,cyc)==0) st[N]=2,b[N][2]=id[vec];
			}
		}
	}
	dp[0][1]=1;
	rep(i,1,N)
	{
		rep(j,1,tot) dp[i&1][j]=dp[(i-1)&1][j];
		rep(j,1,tot) rep(l,0,st[i])
		{
			int cid=sv[j][b[i][l]];
			if(cid!=-1) add(dp[i&1][cid],dp[(i-1)&1][j]);
		}
	}
	int ans=0;
	rep(j,1,tot) add(ans,dp[N&1][j]);
	printf("%d\n",ans);
	return 0;
}
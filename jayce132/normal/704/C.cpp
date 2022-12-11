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
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
inline int read()
{
	int s=0,f=1; char ch=getchar();
	while(!isdigit(ch) && ch!='-')ch=getchar();
	if(ch=='-')ch=getchar(),f=-1;
	while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
	return ~f?s:-s;
}

const int maxn=1e5+20;
const int mod=1e9+7;
inline void pls(int &a,int b){ a+=b; a-=a>=mod?mod:0;}

int n,m;

struct Edge {
	int u,v,s;
};
Edge E[maxn];
vector<int>ed[maxn];

inline void init()
{
	n=read();m=read();
	REP(i,1,n)
	{
		int k=read();
		while(k--)
		{
			int x=read(),id=abs(x);
			E[id].s^=x<0;
			if(!E[id].u)E[id].u=i;
			else E[id].v=i;
			ed[i].push_back(id);
		}
	}
}

int ans[2];
int cir[maxn],ct;
int vis[maxn];

void dfs(int u)
{
	for(int i:ed[u])
		if(!vis[i])
		{
			vis[i]=1; cir[++ct]=i;
			int v=E[i].u^E[i].v^u;
			dfs(v);
		}
}

int dp[maxn][2][2][2];

inline void doing()
{
	ans[0]=1;
	REP(i,1,m)if(!vis[i])
	{
		vis[i]=1;
		ct=0;
		if(E[i].u)dfs(E[i].u);
		reverse(cir+1,cir+ct+1);
		cir[++ct]=i;
		if(E[i].v)dfs(E[i].v);
		memset(dp,0,sizeof(int)*(ct+1)*8);
		dp[0][0][0][0]=1;
		if(ct>=2 && (E[cir[1]].u==E[cir[2]].u || E[cir[1]].u==E[cir[2]].v))
			swap(E[cir[1]].u,E[cir[1]].v);
		int ST=E[cir[1]].u;		if(!ST)ST=-1;
		if(ct>=2 && E[cir[ct]].u==0 && (E[cir[ct-1]].u==E[cir[ct]].v || E[cir[ct-1]].v==E[cir[ct]].v))swap(E[cir[ct]].u,E[cir[ct]].v);
		if(E[cir[ct]].u==ST)swap(E[cir[ct]].u,E[cir[ct]].v);
		REP(i,1,ct)
		{
			Edge Enow=E[cir[i]];
			REP(oplst,0,1)REP(opst,0,1)REP(opall,0,1)if(dp[i-1][oplst][opst][opall])
			{
				int t=dp[i-1][oplst][opst][opall];
				REP(opnow,0,1)
				{
					pls(dp[i][(Enow.v!=ST && Enow.v)&(opnow^Enow.s)][opst | ((Enow.u==ST)&opnow) | ((Enow.v==ST)&(opnow^Enow.s))][opall^(i>1 && (oplst|opnow))],t);
				}
			}
		}
		static int num[2],g[2]; num[0]=num[1]=0; g[0]=g[1]=0;
		REP(oplst,0,1)REP(opst,0,1)REP(opall,0,1)
			pls(num[opst^opall^oplst],dp[ct][oplst][opst][opall]);
		REP(a,0,1)REP(b,0,1)g[a^b]=(g[a^b]+(ll)ans[a]*num[b])%mod;
		REP(a,0,1)ans[a]=g[a];
	}
	printf("%d\n",ans[1]);
}

int main()
{
#ifndef ONLINE_JUDGE	
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}
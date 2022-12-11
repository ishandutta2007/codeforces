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

#define index Index

const int maxn=8e3+20;

int n;
int f[maxn][maxn];
int cd[maxn];

inline void init()
{
    n=read();
    REP(i,1,n)
    {
	static char str[maxn];
	scanf("%s",str+1);
	REP(j,1,n>>2)
	{
	    int x=str[j]<='9'?str[j]-'0':str[j]-'A'+10;
	    REP(k,0,3)f[i][j*4-k]=x>>k&1,cd[i]+=f[i][j*4-k];
	}
    }
}

int rk[maxn],tp;

int index;

inline bool cmp(int x,int y)
{
    return f[index][x]!=f[index][y]?f[index][x]:f[y][x];
}

const int mod=998244353;
int hs[maxn];
int dis[maxn][maxn];

inline void bfs()
{
    REP(S,1,n)
    {
	queue<int>q;
	REP(i,1,n)dis[S][i]=-1;
	q.push(S); dis[S][S]=0;
	while(!q.empty())
	{
	    int u=q.front();q.pop();
	    REP(v,1,n)if(f[u][v] && dis[S][v]==-1)
		dis[S][v]=dis[S][u]+1,q.push(v);
	}
    }
}

inline void doing()
{
    index=0; int T;
    REP(i,1,n)if(!index || cd[index]>cd[i])
	index=i;
    REP(i,1,n)rk[i]=i;
    sort(rk+1,rk+n+1,cmp);
    REP(i,1,n)if(rk[i]==index)T=i;
    ll ans=0;
    int len=0;
    DREP(i,n,1)if(cd[rk[i]]==i-1)
    {
	ans=(ans+(i-1)+(ll)614*n*(i-1));
    }else { len=i; break;}
    static int pw[maxn],out[maxn];
    REP(i,1,len)
    {
	if(i<T)
	{
	    REP(j,T,len)if(f[rk[i]][rk[j]])out[i]++;
	}else if(i>T)REP(j,1,T-1)if(f[rk[j]][rk[i]])out[i]++;
    }
    //bfs();
    ans+=(ll)3*(T-1)*(len-T+1);
    REP(i,1,len)REP(j,1,len)
    {
	int x=rk[i],y=rk[j];
	if(x==y)continue;
	if(i<T && j<T)
	{
	    if(i>j)ans+=1;
	    else if(out[i]==out[j])
		ans+=3;
	    else ans+=2;
	}else if(i>=T && j>=T)
	{
	    if(i>j)ans+=1;
	    else if(out[i]==out[j])
		ans+=3;
	    else ans+=2;
	}
    }
    printf("%lld\n",ans);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1338e.in","r",stdin);
    freopen("1338e.out","w",stdout);
#endif
    init();
    doing();
    return 0;
}
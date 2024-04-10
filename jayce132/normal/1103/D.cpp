#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,u) for(int i=start[u];i;i=e[i].next)
#define fi first
#define se second
#define mkr(a,b) make_pair(a,b)
template <class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
template <class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}

inline ll read()
{
    ll sum=0;int f=1; char ch=getchar();
    while(!('0'<=ch && ch<='9') && ch!='-')ch=getchar();
    if(ch=='-')ch=getchar(),f=-1;
    while('0'<=ch && ch<='9')sum=sum*10+ch-'0',ch=getchar();
    return ~f?sum:-sum;
}

const int maxn=1e6+20;

int n;
ll k;
ll D;

ll rk[50],s[50],p[50],tp;
ll pw[50][50];

inline void fj(ll x)
{
    for(int i=2;(ll)i*i<=x;i++)
		if(x%i==0)
		{
			rk[++tp]=i; p[tp]=1;
			while(!(x%i))x/=i,s[tp]++,p[tp]=p[tp]*i;
		}
    if(x>1)rk[++tp]=x,p[tp]=rk[tp],s[tp]=1;
}

struct node {
    ll x,d;
};
node a[maxn];

inline bool cmp(node a,node b){ return a.d<b.d;}

ll f[12][1<<11],g[12][1<<11];

map<int,int>mp;

int tot;
int b[100000][50];ll pb[100000][50];
vector<ll>bw[100000];

const int mod=1e9+7;
const int seed=181;

int Get_Hash(int *p)
{
    int hs=0;
    REP(i,1,tp)hs=((ll)hs*seed+p[i])%mod;
    return hs;
}

inline void py(ll x,ll d)
{
    static int tmp[50];
    REP(i,1,tp)
    {
		tmp[i]=0;
		while(!(x%rk[i]))x/=rk[i],tmp[i]++;
    }
    
    int hs=Get_Hash(tmp);
    if(!mp.count(hs))
    {
		mp[hs]=++tot;
		REP(j,1,tp)b[tot][j]=tmp[j],pb[tot][j]=pw[j][tmp[j]];
    }
    int id=mp[hs];
    if((int)bw[id].size()<tp)bw[id].push_back(d);
}

inline void init()
{
    n=read();k=read();
    REP(i,1,n)a[i].x=read(),D=__gcd(D,a[i].x);
    REP(i,1,n)a[i].d=read();
    sort(a+1,a+n+1,cmp);
    if(D==1)puts("0"),exit(0);
    fj(D);
    REP(i,1,tp)
    {
		pw[i][0]=1;
		REP(j,1,49)pw[i][j]=(ll)pw[i][j-1]*rk[i];
    }
    REP(i,1,n)py(a[i].x,a[i].d);
}

int st[maxn],top;

void dfs(int id,int u,int s,ll rest)
{
    int flg=0;
    REP(i,1,tp)if((~s>>i-1&1) && pb[id][i]<=rest)
    {
		flg=1;
		if(i>=u)dfs(id,i+1,s|(1<<i-1),rest/pb[id][i]);
    }
	//if(!flg)
	st[++top]=s;
}

ll inf;

struct Node {
	ll w,id;
};
Node E[maxn];
int etot;

inline bool cmp1(Node a,Node b){ return a.w<b.w;}

vector<int>dr[100000];

int Count[1<<11];

inline void doing()
{
    memset(f,63,sizeof(f)); memset(g,63,sizeof(g));
    inf=f[0][0];
    f[0][0]=0;
    REP(i,1,tot)
    {
		top=0;
		dfs(i,1,0,k);
		REP(j,1,top)dr[i].push_back(st[j]);
		REP(_xh_w,0,(int)bw[i].size()-1)
		{
			ll w=bw[i][_xh_w];
			E[++etot]=(Node){w,i};
            /*REP(j,1,top)if(st[j]>0)
			{
				int S=st[j],re=(1<<tp)-1^S;
				for(int T=re;;T=(T-1)&re)
				{
					REP(num,0,__builtin_popcount(T))chkmin(g[num+1][T|S],f[num][T]+w);
					if(!T)break;
					}
			}
			REP(num,0,tp)REP(T,0,(1<<tp)-1)chkmin(f[num][T],g[num][T]);
			*/
		}
    }
	sort(E+1,E+etot+1,cmp1);

	REP(i,1,etot)
	{
		int id=E[i].id;
		REP(l,0,(int)dr[id].size()-1)
		{
			int S=dr[id][l];
			if(S>0 && (++Count[S])<=tp)
			{
				int re=(1<<tp)-1^S;
				for(int T=re;;T=(T-1)&re)
				{
					REP(num,0,__builtin_popcount(T))chkmin(g[num+1][T|S],f[num][T]+E[i].w);
					if(!T)break;
				}
			}
		}
		REP(num,0,tp)REP(T,0,(1<<tp)-1)chkmin(f[num][T],g[num][T]);
		
	}
	
    ll ans=1ll<<60;
    REP(j,0,tp)if(f[j][(1<<tp)-1]!=inf)
		chkmin(ans,j*f[j][(1<<tp)-1]);
    if(ans==(1ll<<60))puts("-1");
    else printf("%lld\n",ans);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
#endif
	init();
    doing();
    return 0;
}
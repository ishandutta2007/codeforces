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
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch) && ch!='-')ch=getchar();
	if(ch=='-')ch=getchar(),f=-1;
	while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
	return ~f?s:-s;
}

const int maxt=(1<<16)+20;
const int MAX=1<<16;
const int maxn=120;
const double inf=1e10;
const double Pi=acos(-1);

#define complex Complex

struct complex {
	double a,b;
	complex(double _a=0,double _b=0){ a=_a; b=_b;}
};

inline complex operator +(complex x,complex y){ return complex(x.a+y.a,x.b+y.b);}
inline complex operator -(complex x,complex y){ return complex(x.a-y.a,x.b-y.b);}
inline complex operator *(complex x,complex y){ return complex(x.a*y.a-x.b*y.b,x.a*y.b+x.b*y.a);}
inline void operator /=(complex &x,int y){ x=complex(x.a/y,x.b/y);}

complex W[maxt];

inline void prepare()
{
	REP(j,0,MAX-1)W[j]=complex(cos(2*Pi*j/MAX),sin(2*Pi*j/MAX));
}

inline void FFT(complex *p,int n,int op)
{
	static int rev[maxt],l;
	l=0; while(1<<l<n)l++;
	REP(i,1,n-1)rev[i]=(rev[i>>1]>>1)|((i&1)<<l-1);
	REP(i,1,n-1)if(i<rev[i])swap(p[i],p[rev[i]]);
	for(int i=1;i<n;i<<=1)
		for(int j=0,w=(MAX/(i<<1));j<n;j+=i<<1)
			for(int k=0;k<i;k++)
			{
				complex x=p[j+k],y=p[i+j+k]*W[w*k];
				p[j+k]=x+y;
				p[i+j+k]=x-y;
			}
	if(op==-1)
	{
		REP(i,0,n-1)p[i]/=n;
		reverse(p+1,p+n);
	}
}

vector<int>ed[maxn];
int u[maxn],v[maxn],w[maxn];
double p[maxn][maxt],g[maxn][maxt];

int n,m,t,X;

double f[maxn][maxt];

int dist[maxn];

#define pii pair<int,int>

inline void DIJ()
{
	static int vis[maxn];
	priority_queue<pii,vector<pii>,greater<pii>>q;
	REP(i,1,n)dist[i]=0x3f3f3f3f,vis[i]=0;
	dist[n]=0;
	q.push(mkr(dist[n],n));
	while(!q.empty())
	{
		int V=q.top().se;q.pop();
		if(vis[V])continue;
		vis[V]=1;
		for(int i:ed[V])
		{
			if(dist[u[i]]>dist[v[i]]+w[i])
			{
				dist[u[i]]=dist[v[i]]+w[i];
				q.push(mkr(dist[u[i]],u[i]));
			}
		}
	}
}

inline void init()
{
	n=read();m=read();t=read();X=read();
	REP(i,1,m)
	{
		u[i]=read(); v[i]=read(); w[i]=read();
		ed[v[i]].push_back(i);
		REP(j,1,t)p[i][j]=read()/1e5;
		REP(j,0,t+1)g[i][j]+=w[i];
	}
	memset(f,100,sizeof(f));
	DIJ();
	REP(j,0,t)f[n][j]=j==0?X:0;
	REP(i,1,n-1)f[i][0]=dist[i]+X;
}

void solve(int l,int r)
{
	if(l==r)
	{
		if(l==0)return;
		REP(i,1,m)
		{
			if(f[u[i]][l]>g[i][l])
				f[u[i]][l]=g[i][l];
		}
		return;
	}
	int mid=l+r>>1;
	solve(l,mid);

	REP(i,1,m)
	{
		
		static complex A[maxt],B[maxt];
		int N=1; while(N<=(mid-l+1+r-l))N<<=1;
		memset(A,0,sizeof(complex)*N);
		memset(B,0,sizeof(complex)*N);
		REP(j,l,mid)A[j-l]=f[v[i]][j];
		REP(j,1,r-l)B[j]=p[i][j];
		FFT(A,N,1); FFT(B,N,1);
		REP(j,0,N-1)A[j]=A[j]*B[j];
		FFT(A,N,-1);
		
		REP(j,mid+1,r)
			g[i][j]+=A[j-l].a;
	}
	
	solve(mid+1,r);
}

inline void doing()
{
	REP(i,1,m)
	{
		double s=0;
		DREP(j,t,1)s+=p[i][j],g[i][j]+=f[v[i]][0]*s;
	}
	solve(1,t+1);
	printf("%.10lf\n",f[1][t+1]);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("CF553E.in","r",stdin);
	freopen("CF553E.out","w",stdout);
#endif
	prepare();
	init();
	doing();
	return 0;
}
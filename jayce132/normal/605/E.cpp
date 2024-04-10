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

const int maxn=1e3+20;

int n;
double p[maxn][maxn];

inline void init()
{
	n=read();
	REP(i,1,n)REP(j,1,n)p[i][j]=(double)read()/100;
}

double gl[maxn];
double val[maxn],f[maxn];
int vis[maxn];

inline void doing()
{
	REP(i,1,n-1)gl[i]=1;
	memset(val,100,sizeof(val));
	val[n]=0;
	REP(i,1,n)f[i]=1;
	REP(th,1,n)
	{
		int u=-1;
		REP(j,1,n)if(!vis[j] && (u==-1 || val[u]>val[j]))u=j;
		vis[u]=1; 
		REP(j,1,n)if(!vis[j] && p[j][u]>0)
			f[j]+=gl[j]*p[j][u]*(val[u]),gl[j]*=1-p[j][u],val[j]=f[j]/(1-gl[j]);
	}
	printf("%.10lf\n",val[1]);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("CF605E.in","r",stdin);
	freopen("CF605E.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}
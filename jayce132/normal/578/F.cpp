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
inline void myassert(bool a,string s){ if(!a)cerr<<s<<endl,exit(0);}
inline int read()
{
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch) && ch!='-')ch=getchar();
	if(ch=='-')ch=getchar(),f=-1;
	while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
	return ~f?s:-s;
}

const int maxn=400+20;
int n,m,mod;

inline int power(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)ans=(ll)ans*a%mod;
		b>>=1;
		a=(ll)a*a%mod;
	}
	return ans;
}

char str[maxn][maxn];
int num[maxn][maxn],tot;
int fa[maxn*maxn],to[maxn*maxn],ntot;
int fin(int x){ return x==fa[x]?x:fa[x]=fin(fa[x]);}
inline void merge(int x,int y){ x=fin(x); y=fin(y); fa[y]=x;}

inline void init()
{
	n=read();m=read(); mod=read();
	REP(i,1,n)scanf("%s",str[i]+1);
	REP(i,0,n)REP(j,0,m)num[i][j]=++tot,fa[tot]=tot;
	REP(i,1,n)REP(j,1,m)
	{
		if(str[i][j]=='/')merge(num[i-1][j],num[i][j-1]);
		else if(str[i][j]=='\\')merge(num[i-1][j-1],num[i][j]);
	}
}

inline int Det(int n,int A[maxn][maxn])
{
	int ans=1;
	REP(i,1,n)REP(j,1,n)A[i][j]%=mod;
	REP(i,1,n)
	{
		if(!A[i][i])
		{
			REP(j,i+1,n)
			{
				if(A[j][i])
				{
					REP(l,i,n)swap(A[i][l],A[j][l]);
					ans=-ans;
				}
			}
		}

		int inv=power((A[i][i]+mod)%mod,mod-2);
		REP(j,i+1,n)
		{
			int t=(ll)A[j][i]*inv%mod;
			REP(l,i,n)A[j][l]=(A[j][l]-(ll)t*A[i][l])%mod;
		}
		ans=(ll)ans*A[i][i]%mod;
	}
	ans=(ans+mod)%mod;
	return ans;
}

int A[maxn][maxn];
int ans;

inline void doing()
{
	ntot=0;
	//odd
	REP(i,0,n)REP(j,0,m)if(i+j&1)
	{
		int x=fin(num[i][j]);
		if(!to[x])to[x]=++ntot;
	}
	memset(A,0,sizeof(A));
	REP(i,1,n)REP(j,1,m)if(str[i][j]=='*')
	{
		int x,y;
		if(i+j&1) x=to[fin(num[i-1][j-1])],y=to[fin(num[i][j])];
		else x=to[fin(num[i][j-1])],y=to[fin(num[i-1][j])];
		A[x][y]--; A[y][x]--; A[x][x]++; A[y][y]++;
	}
	ans=(ans+Det(ntot-1,A))%mod;
	//even
	ntot=0;
	memset(to,0,sizeof(to));
	REP(i,0,n)REP(j,0,m)if(~i+j&1)
	{
		int x=fin(num[i][j]);
		if(!to[x])to[x]=++ntot;
	}
	memset(A,0,sizeof(A));
	REP(i,1,n)REP(j,1,m)if(str[i][j]=='*')
	{
		int x,y;
		if(~i+j&1) x=to[fin(num[i-1][j-1])],y=to[fin(num[i][j])];
		else x=to[fin(num[i][j-1])],y=to[fin(num[i-1][j])];
		assert(0<x && x<=ntot ); assert(0<y && y<=ntot);
		A[x][y]--; A[y][x]--; A[x][x]++; A[y][y]++;
	}
	ans=(ans+Det(ntot-1,A))%mod;
	printf("%d\n",ans);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("mirror.in","r",stdin);
	freopen("mirror.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}
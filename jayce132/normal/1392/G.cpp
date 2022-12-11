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

const int maxn=(1<<20)+20;
const int inf=0x3f3f3f3f;

int n,n1,n2,k;
int mx,m;

int x[maxn],y[maxn];
int a1,a2;

int A[maxn],B[maxn];

inline int Swap(int a,int x,int y)
{
	if(x==y)return a;
	int ax=a>>x-1&1,ay=a>>y-1&1;
	int na=a^(ax<<x-1)^(ay<<y-1);
	swap(ax,ay);
	return na|(ax<<x-1)|(ay<<y-1);
}

int vis[maxn];
int Ak[maxn],Bk[maxn];
int N1,N2;
int p1[maxn],p2[maxn];

inline int SWAP(int a,int *p)
{
	static int pp[maxn];
	REP(i,1,k)pp[i]=p[i];
	REP(i,1,k)if(p[i]!=i)
	{
		while(p[i]!=i)
		{
			int x=p[i];
			swap(p[i],p[x]);
			a=Swap(a,i,x);
		}
	}
	REP(i,1,k)p[i]=pp[i];
	return a;
}

inline void init()
{
	n=read();m=read(); k=read(); 
	static char str[maxn];
	scanf("%s",str+1); REP(i,1,k)a1|=str[i]-'0'<<i-1;
	scanf("%s",str+1); REP(i,1,k)a2|=str[i]-'0'<<i-1;
	REP(i,1,n)x[i]=read(),y[i]=read();
	A[n+1]=a1; B[n+1]=a2;
	REP(i,1,k)p1[i]=p2[i]=i;
	n1=__builtin_popcount(a1);
	n2=__builtin_popcount(a2);
	DREP(i,n,1)
	{
		swap(p1[x[i]],p1[y[i]]);
		swap(p2[x[i]],p2[y[i]]);
		A[i]=SWAP(a1,p1);
		B[i]=SWAP(a2,p2);
	}
	n++;
}

int s1[maxn],s2[maxn];

inline void doing()
{
	REP(i,0,(1<<k)-1)s1[i]=inf,s2[i]=-inf;
	REP(i,1,n)chkmin(s1[A[i]],i),chkmax(s2[B[i]],i);
	for(int i=1;i<(1<<k);i<<=1)
		for(int j=0;j<(1<<k);j+=i<<1)
			for(int k=0;k<i;k++)
			{
				chkmin(s1[j+k],s1[i+j+k]);
				chkmax(s2[j+k],s2[i+j+k]);
			}
	int nl=0,nr=0;
	mx=-inf;
	REP(i,0,(1<<k)-1)
		if(s2[i]-s1[i]>=m)
		{
			int tmp=__builtin_popcount(i);
			if(tmp>mx)
			{
				mx=tmp;
				nl=s1[i],nr=s2[i]-1;
			}
		}
	printf("%d\n",k-(n1-mx)-(n2-mx));
	printf("%d %d\n",nl,nr);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("g.in","r",stdin);
	freopen("g.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}
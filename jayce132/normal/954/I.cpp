#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<cassert>
#include<vector>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,a) for(int i=start[(a)];i;i=e[i].next)
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
#define fi first
#define se second
#define mkr(a,b) make_pair(a,b)
inline int read()
{
	int sum=0,p=1;char ch=getchar();
	while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
	if(ch=='-')p=-1,ch=getchar();
	while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
	return sum*p;
}

const int maxn=2.7e5;

struct complex {
	double a,b;
	complex(double _a=0,double _b=0){ a=_a; b=_b;}
};

inline complex operator *(complex x,complex y){ return complex(x.a*y.a-x.b*y.b,x.a*y.b+x.b*y.a);}
inline complex operator +(complex x,complex y){ return complex(x.a+y.a,x.b+y.b);}
inline complex operator -(complex x,complex y){ return complex(x.a-y.a,x.b-y.b);}
inline void operator /=(complex &x,int y){ x.a/=y; x.b/=y;}

int rev[maxn];
complex st[maxn];

const double Pi=acos(-1);

inline void FFT(complex *p,int n,int op)
{
	int l=0;
	while((1<<l)<n)l++;
	REP(i,1,n-1)rev[i]=(rev[i>>1]>>1)|((i&1)<<l-1);
	REP(i,1,n-1)if(i<rev[i])swap(p[i],p[rev[i]]);
	for(int i=1;i<n;i<<=1)
	{
		REP(j,0,i-1)st[j]=complex(cos(Pi*j/i),~op?sin(Pi*j/i):-sin(Pi*j/i));
		for(int j=0;j<n;j+=i<<1)
			for(int k=0;k<i;k++)
			{
				complex x=p[j+k],y=st[k]*p[i+j+k];
				p[j+k]=x+y; p[i+j+k]=x-y;
			}
	}
	if(op==-1)REP(i,0,n-1)p[i]/=n;
}

int n,m;
char S[maxn],T[maxn];

inline void init()
{
	scanf("%s",S);n=strlen(S);
	scanf("%s",T);m=strlen(T);
	reverse(T,T+m);
}

complex a[maxn],b[maxn];
int fa[maxn][7];

inline int fin(int x,int *fa)
{
	return x==fa[x]?x:fa[x]=fin(fa[x],fa);
}

inline void merge(int x,int y,int *fa)
{
	x=fin(x,fa); y=fin(y,fa);
	fa[y]=x;
}

inline void doing()
{
	int N=1;
	while(N<(n+m-1))N<<=1;
	REP(i,0,n-m)REP(j,1,6)fa[i][j]=j;
	REP(i,1,6)REP(j,1,6)if(i!=j)
	{
		memset(a,0,sizeof(complex)*N);
		memset(b,0,sizeof(complex)*N);
		REP(l,0,n-1)a[l]=complex(S[l]=='a'+i-1,0);
		REP(l,0,m-1)b[l]=complex(T[l]=='a'+j-1,0);
		FFT(a,N,1); FFT(b,N,1);
		REP(l,0,N-1)a[l]=a[l]*b[l];
		FFT(a,N,-1);
		REP(l,0,n-m)if(a[l+m-1].a>0.5)merge(i,j,fa[l]);
	}
	REP(i,0,n-m)
	{
		int ans=6;
		REP(j,1,6)if(fin(j,fa[i])==j)ans--;
		printf("%d ",ans);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}
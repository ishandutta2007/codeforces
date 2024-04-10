#include<bits/stdc++.h>
using namespace std;

template <typename T> void chmin(T&x,const T &y)
{
	if(x>y)x=y;
}
template <typename T> void chmax(T &x,const T &y)
{
	if(x<y)x=y;
}
typedef long long s64;
typedef unsigned long long u64;
typedef unsigned int u32;
typedef pair<int,int> pii;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
#define rep0(i,l,r) for(int i=l;i<r;++i)
#define gc (c=getchar())
int read()
{
	char c;
	while(gc<'-');
	if(c=='-')
	{
		int x=gc-'0';
		while(gc>='0')x=x*10+c-'0';
		return -x;
	}
	int x=c-'0';
	while(gc>='0')x=x*10+c-'0';
	return x;
}
#undef gc

const int N=4000+5,M=N*2,K=80,D=998244353;
s64 mi(s64 x,int y=D-2)
{
	s64 ans=1;
	while(y)
	{
		if(y&1)ans=ans*x%D;
		x=x*x%D;y>>=1;
	}
	return ans;
}

int k,t[N],to[M],nex[M];
s64 f[N][K],fe[M][K],g[M][K],F[2][K];
s64 jie[K];
s64 C(int n,int m)
{
	return jie[n]*mi(jie[m]*jie[n-m]%D)%D;
}

void get(int n,s64 F[])
{
	rep(i,1,n)t[i]=0;
	rep(i,1,n-1)
	{
		int x=read(),y=read();
		to[i*2]=y;nex[i*2]=t[x];t[x]=i*2;
		to[i*2+1]=x;nex[i*2+1]=t[y];t[y]=i*2+1;
	}
	rep(i,1,n)f[i][0]=1;
	rep(i,2,n*2-1)g[i][0]=1;
	rep(j,1,k)
	{
		rep(u,1,n)
		{
			s64 ans=0;
			for(int i=t[u];i;i=nex[i])(ans+=fe[i^1][j-1])%=D;
			f[u][j]=ans;
		}
		rep(i,2,n*2-1)
		{
			int u=to[i^1],v=to[i];
			s64 ans=0;
			rep(x,0,j-1)(ans+=g[i][x]*f[v][j-1-x])%=D;
			fe[i][j]=ans;

			ans=f[u][j];
			rep(x,0,j-1)(ans-=g[i][x]*fe[i^1][j-x-1])%=D;
			g[i][j]=ans;
		}
	}
	rep(j,0,k)
	{
		s64 ans=0;
		rep(i,1,n)ans+=f[i][j];
		F[j]=ans%D;
	}
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int n1=read(),n2=read();k=read();
	get(n1,F[0]);
	get(n2,F[1]);

	jie[0]=1;
	rep(i,1,k)jie[i]=jie[i-1]*i%D;
	s64 ans=0;
	rep(x,0,k)(ans+=F[0][x]*F[1][k-x]%D*C(k,x))%=D;
	cout<<(ans+D)%D;
}
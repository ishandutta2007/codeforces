#include<bits/stdc++.h>
using namespace std;

template <typename T> void chmin(T &x,const T &y)
{
	if(x>y)x=y;
}
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
const int N=50+5,M=100+5,T=2e4+5;
int n,m,t;
double dp[N][T],ans[M][T],p[M][T],suf[M][T];
int a[M],b[M],c[M];

namespace FFT
{
const int N=1e5;const double pi=acos(-1);
struct Complex
{
	double x,y;
};
Complex operator *(const Complex &a,const Complex &b)
{
	return {a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x};
}
Complex operator +(const Complex &a,const Complex &b)
{
	return {a.x+b.x,a.y+b.y};
}
Complex operator -(const Complex &a,const Complex &b)
{
	return {a.x-b.x,a.y-b.y};
}
Complex a[N],b[N],c[N],w[N];
int rev[N];
void fft(Complex a[],int n,int flag)
{
	rep(i,1,n-1)rev[i]=rev[i/2]/2+i%2*n/2;
	rep(i,0,n-1)
	if(i<rev[i])swap(a[i],a[rev[i]]);
	for(int i=1;i<n;i*=2)
	{
		Complex wn={cos(flag*2*pi/(i*2)),sin(flag*2*pi/(i*2))};
		w[0]={1,0};
		rep(k,1,i-1)w[k]=w[k-1]*wn;
		for(int j=0;j<n;j+=i*2)
		{
			Complex *a1=a+j,*a2=a1+i;
			rep(k,0,i-1)
			{
				Complex x=a1[k],y=a2[k]*w[k];
				a1[k]=x+y;
				a2[k]=x-y;
			}
		}
	}
	if(flag==-1)rep(i,0,n-1)a[i].x/=n;
}
void mul(int n)
{
/*	rep(i,0,n-1)c[i]={0,0};
	rep(i,0,n-1)
	rep(j,0,n-1)
	if(i+j<n)c[i+j]=c[i+j]+a[i]*b[j];*/
	fft(a,n,1);
	fft(b,n,1);
	rep(i,0,n-1)c[i]=a[i]*b[i];
	fft(c,n,-1);
}
};

void solve(int l,int r)
{
	if(l==r)
	{
		rep(i,1,n-1)dp[i][l]=1e9;
		rep(i,1,m)chmin(dp[a[i]][l],ans[i][l]+c[i]+suf[i][t-l+1]*dp[b[i]][t+1]);
		return ;
	}
	int mid=(l+r)/2;
	solve(mid+1,r);
	rep(e,1,m)
	{
		int n1=r-mid,n2=r-l;
		int n=1;
		while(n<=n1+n2-2)n*=2;
		rep(i,0,n-1)FFT::a[i]=FFT::b[i]={0,0};
		rep(i,0,n1-1)FFT::a[i]={dp[b[e]][mid+1+i],0};
		rep(i,0,n2-1)FFT::b[i]={p[e][n2-i],0};
		FFT::mul(n);
		rep(i,l,mid)ans[e][i]+=FFT::c[i-l+r-(mid+1)].x;
	}
	solve(l,mid);
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);
#endif
	int x;
	cin>>n>>m>>t>>x;
	rep(i,1,m)
	{
		scanf("%d%d%d",a+i,b+i,c+i);
		rep(j,1,t)
		{
			int x;
			scanf("%d",&x);
			p[i][j]=x/100000.0;
		}
		per(j,t,1)suf[i][j]=suf[i][j+1]+p[i][j];
	}
	rep(i,1,n)dp[i][t+1]=1e9;
	dp[n][t+1]=x;
	rep(tmp,1,n)
	rep(i,1,m)chmin(dp[a[i]][t+1],dp[b[i]][t+1]+c[i]);
	solve(0,t);
	printf("%.9f\n",dp[1][0]);
}
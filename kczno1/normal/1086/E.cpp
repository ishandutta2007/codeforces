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

const int N=2000+5,D=998244353;
s64 w[N][N],dp2[N];
int c[2][N],ap[2][N];
int a[N][N],n;

void add(int c[],int i,int w)
{
	for(;i<=n;i+=i&-i)c[i]+=w;
}
int qiu(int c[],int i)
{
	int ans=0;
	for(;i;i-=i&-i)ans+=c[i];
	return ans;
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	cin>>n;
	rep(i,1,n)
	rep(j,1,n)a[i][j]=read();
	w[0][0]=1;
	rep(i,1,n)
	{
		w[i][0]=w[i-1][0]*i%D;
		rep(b,1,i)w[i][b]=((b>1?(b-1)*w[i-1][b-2]:0)+(i-b)*w[i-1][b-1])%D;
	}
	dp2[1]=1;
	rep(i,2,n)dp2[i]=dp2[i-1]*w[n][n]%D;
	s64 Ans=0;
	rep(i,1,n)
	{
		rep(j,1,n)c[0][j]=c[1][j]=ap[0][j]=ap[1][j]=0;
		int ap10=0;s64 ans=0;
		rep(j,1,n)
		{
			if(i==1)
			{
				int c0=a[i][j]-1-qiu(c[0],a[i][j]);
				(ans+=c0*w[n-j][0])%=D;
				add(c[0],a[i][j],1);
				continue;
			}
			++ap[1][a[i-1][j]];
			if(!ap[0][a[i-1][j]]){add(c[1],a[i-1][j],1);++ap10;}
			int c0=a[i][j]-1-qiu(c[0],a[i][j]-1),c1=qiu(c[1],a[i][j]-1);
			(ans+=(c1-(a[i-1][j]<a[i][j]&&!ap[0][a[i-1][j]]))*w[n-j][max(0,n-j-(ap10-1))]+
			(c0-c1)*w[n-j][max(0,n-j-ap10)])%=D;
		//	if(i==3)
		//		int yyx=1;
			++ap[0][a[i][j]];
			add(c[0],a[i][j],1);		
			if(ap[1][a[i][j]]){--ap10;add(c[1],a[i][j],-1);}
		}
		(Ans+=ans*dp2[n-i+1])%=D;	
	}
	cout<<Ans;
}
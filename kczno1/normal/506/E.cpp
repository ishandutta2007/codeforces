#include<bits/stdc++.h>
using namespace std;

typedef long long s64;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
const int N=200+5,T=N*2,D=10007;	 
char s[N];
struct Matrix
{
	int a[T][T];
	int* operator [] (int x)
	{
		return a[x];
	}
	const int* operator [] (int x)const
	{
		return a[x];
	}
}a;
int tot;
Matrix operator *(const Matrix &a,const Matrix &b)
{
	Matrix ans={};
	rep(i,1,tot)
	{
		int *a1=ans[i];
	rep(k,1,tot)
	{
		int d=a[i][k];
		if(d)
		{
			const int *a2=b[k];
			rep(j,1,tot)a1[j]+=d*a2[j];
		}
		if(k==tot||k%20==0)rep(j,1,tot)a1[j]%=D;
	}
	}
	return ans;
}
Matrix mi(Matrix x,int y)
{
	Matrix ans={};
	rep(i,1,tot)ans[i][i]=1;
	while(y)
	{
		if(y&1)ans=ans*x;
		x=x*x;y>>=1;
	}
	return ans;
}

int dp[N][N][N];

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);
#endif	
	scanf("%s",s+1);
	int m;cin>>m;
	int n=strlen(s+1);
	m+=n;
	per(l,n,1)
	{
		dp[l][l][0]=1;
		if(s[l]==s[l+1])dp[l][l+1][0]=1;
		else dp[l][l+1][1]=2;
		rep(r,l+2,n)
		if(s[l]==s[r])rep(i,0,r-l)dp[l][r][i]=dp[l+1][r-1][i];
		else rep(i,1,r-l)dp[l][r][i]=(dp[l+1][r][i-1]+dp[l][r-1][i-1])%D;
	}
	
	int half=(n+1)/2;
	tot=n+half+half;
	
	rep(i,1,n)a[i][i]=24;
	rep(i,n+1,n+half){a[i][i]=25;a[i][i+half]=1;}
	rep(i,n+half+1,tot)a[i][i]=26;
	rep(i,1,n+half-1)a[i][i+1]=1;
	
	Matrix b=mi(a,(m-1)/2),c=a*b;
	s64 ans=0;
	rep(i,0,n)
	if(dp[1][n][i])
	{
		int j=(n-i+1)/2;
		s64 x=c[n-i+1][n+j+half];
		if(m%2&&(n-i)%2==0)x-=b[n-i+1][n+j];
		ans+=dp[1][n][i]*x;
	}
	cout<<(ans%D+D)%D;
}
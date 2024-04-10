#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define per(i,n) for ((i)=n;(i)>=(1);(i)--)
using namespace std;

long long phi[100005];
long long sphi[100005];
long long ssphi[100005];

long long calc(int l,int r)
{
	long long s=0;
	int i,j;
	for(i=l;i<=r;i=j+1)
	{
		j=r/(r/i);
		s+=sphi[r/i]*(j-i+1);
	}
	return s;
}

void test()
{
	int n,r,i;
	long long ans=1ll<<60;
	cin>>n;
	rep(i,n-1)
	{
		long long tmp=calc(1,i)+calc(i+1,n);
		if(tmp<ans)
		{
			ans=tmp;r=i;
		}
	}
	
	cout<<ans<<' '<<r<<endl;
}

long long dp[25][100005];

void solve(int d,int l,int r,int l2,int r2)
{
	if(l>r) return;
	
	int mid=(l+r)/2,i,s=l2;
	for(i=l2;i<=r2&&i<mid;i++)
	{
		long long tmp=dp[d-1][i]+calc(i+1,mid);
		if(tmp<dp[d][mid])
		{
			dp[d][mid]=tmp;
			s=i;
		}
	}
	
	solve(d,l,mid-1,l2,s);
	solve(d,mid+1,r,s,r2);
}

int lg(int x)
{
	int s=1;
	while(x>1)
	{
		s++;
		x>>=1;
	}
	return s;
}

int main()
{
	int i,j;
	rep(i,100000) phi[i]=i;
	rep(i,100000) rep(j,100000/i) if(j!=1) phi[i*j]-=phi[i];
	rep(i,100000) sphi[i]=sphi[i-1]+phi[i];
	rep(i,100000) ssphi[i]=ssphi[i-1]+sphi[i];
	
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=0;
	
//	cerr<<calc(1,3)<<endl;
	rep(i,20)
	{
		solve(i,i,100000,i-1,100000);
	}
	
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		if(lg(n+1)<=k)
		{
			printf("%d\n",n);
		}
		else
		{
			printf("%lld\n",dp[k][n]);
		}
	}
	return 0;
}
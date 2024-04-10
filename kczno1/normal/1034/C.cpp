#include<bits/stdc++.h>
using namespace std;

typedef long long s64;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
const int N=1e6+5,D=1e9+7;
int a[N],fa[N];s64 sz[N];
int c[N];	
int dp[N];

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);
#endif
	int n;
	cin>>n;
	rep(i,1,n)scanf("%d",a+i);	
	rep(i,2,n)scanf("%d",fa+i);
	per(i,n,1)
	{
		sz[i]+=a[i];
		sz[fa[i]]+=sz[i];
	}
	rep(i,1,n)
	{
		s64 x=sz[i],y=sz[1];
		y/=__gcd(x,y);
		if(y<=n)++c[y];
	}
	per(i,n,1)
	for(int j=i+i;j<=n;j+=i)c[j]+=c[i];
	per(i,n,1)
	if(c[i]==i)
	{
		s64 ans=1;
		for(int j=i+i;j<=n;j+=i)ans+=dp[j];
		dp[i]=ans%D;
	}
	cout<<dp[1];
}
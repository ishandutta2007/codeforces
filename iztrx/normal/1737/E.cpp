#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

#define IOS ios::sync_with_stdio(0)
#define N 1000005

ll T,i,n,g[N],mul[N],sum[N];
ll ksm(ll x,ll y){
	ll ret=1;for(;y;y>>=1,x=x*x%mod)if(y&1)ret=ret*x%mod;return ret;
}
int main()
{
	cin>>T;
	while(T--){
		cin>>n;
		for(i=0;i<=n+2;++i)g[i]=sum[i]=mul[i]=0;
		g[n]=sum[n]=2;
		for (int i=n-1;i>=1;i--)
		{
			int r=(i<<1)-1;
			if (r>n) r=n;
			r++;
			(g[i]+=sum[i+1]-sum[r]+mod)%=mod;
			(sum[i]+=sum[i+1]+g[i])%=mod;
		}
		mul[0]=1;
		for (int a=1;a<=n;a++)
			(mul[a]+=mul[a-1]+mul[a-1])%=mod;
		int ans=ksm(500000004,n);
		for (int i=1;i<=n;i++)
			cout<<1ll*mul[i>>1]*g[i]%mod*ans%mod<<" ";
		cout<<"\n";
	}
	
	return 0;
}
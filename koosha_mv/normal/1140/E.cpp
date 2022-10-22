#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
const int N=3e5+9;
ll mod=998244353,ans=1,p1,p2,n,k,dp1[N][2],dp2[N][2],a[N];
int main(){
	dp1[0][0]=1;
	dp2[0][1]=1;
	cin>>n>>k;
	f(i,1,N){
		dp1[i][0]=dp1[i-1][1];
		dp1[i][1]=(((dp1[i-1][1]*(k-2))%mod)+(dp1[i-1][0]*(k-1)))%mod;
		dp2[i][0]=dp2[i-1][1];
		dp2[i][1]=(((dp2[i-1][1]*(k-2))%mod)+(dp2[i-1][0]*(k-1)))%mod;
	}
	f(i,1,n+1) cin>>a[i];
	for(int i=1;i<n+1;i+=2){
		if(a[i]==-1){
			p2=i;
			while(a[p2]==-1 && p2<=n)
				p2+=2;
			if((i-2<=0 && p2<=n) || (i-2>0 && p2>n))
				ans=(ans*((dp1[(p2-i)/2][0]+dp1[(p2-i)/2][1])%mod))%mod;
			if(i-2<=0 && p2>n)
				ans=(((ans*((dp1[((p2-i)/2)-1][0]+dp1[((p2-i)/2)-1][1])%mod))%mod)*k)%mod;
			if(i-2>0 && p2<=n){
				if(a[i-2]==a[p2])
					ans=(ans*dp1[(p2-i)/2][1])%mod;
				else
					ans=(ans*dp2[(p2-i)/2][1])%mod;
			}
			i=p2;
		}
	}
	for(int i=2;i<n+1;i+=2){
		if(a[i]==-1){
			p2=i;
			while(a[p2]==-1 && p2<=n)
				p2+=2;
			if((i-2<=0 && p2<=n) || (i-2>0 && p2>n))
				ans=(ans*((dp1[(p2-i)/2][0]+dp1[(p2-i)/2][1])%mod))%mod;
			if(i-2<=0 && p2>n)
				ans=(((ans*((dp1[((p2-i)/2)-1][0]+dp1[((p2-i)/2)-1][1])%mod))%mod)*k)%mod;
			if(i-2>0 && p2<=n){
				if(a[i-2]==a[p2])
					ans=(ans*dp1[(p2-i)/2][1])%mod;
				else
					ans=(ans*dp2[(p2-i)/2][1])%mod;
			}
			i=p2;
		}
	}
	f(i,1,n-1){
		if(a[i]==a[i+2] && a[i]!=-1) ans=0;
	}
	cout<<ans;
}
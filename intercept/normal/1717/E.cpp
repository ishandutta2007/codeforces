#include<bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define ll long long
using namespace std;
const int mod=1e9+7;
const int M=1e5+9;
int n,num=0;
int vis[M],pri[M],phi[M],a[M];
int kpow(int x,int y,int rex=1){
	for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)rex=1ll*rex*x%mod;
	return rex;
}
int main(){
	cin>>n;
	for(int i=2;i<=n;++i){
		if(!vis[i])pri[++num]=i,phi[i]=1ll*(i-1)*kpow(i,mod-2)%mod;
		for(int j=1;j<=num&&1ll*pri[j]*i<=n;++j){
			vis[i*pri[j]]=1;
			if(i%pri[j]==0){
				phi[i*pri[j]]=phi[i];
				break;
			}
			phi[i*pri[j]]=1ll*phi[i]*(pri[j]-1)%mod*kpow(pri[j],mod-2)%mod;
		}
	}
	for(int i=2;i<=n;++i){
		for(int j=i;j<=n;j+=i){
			int k=j/i;
			k=k/__gcd(k,n-j);
			a[j]=(a[j]+1ll*phi[i]*i%mod*k%mod)%mod;
		}
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		ans=(ans+1ll*i*a[n-i]%mod)%mod;
	}
	cout<<ans<<"\n";
	return 0;
}
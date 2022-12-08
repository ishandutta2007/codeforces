#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;int k;
const int N=4000010;
const int mod=1e9+7;
ll prime[N],pcnt,cnt[N];

ll qpow(ll a,ll b){
	ll ret=1;for(;b;b>>=1,a=a*a%mod)if(b&1)ret=a*ret%mod;
	return ret;
}

inline void divide(ll n){
	for(ll i=2;i*i<=n;i++){
		if(n%i==0){
			prime[++pcnt]=i;
			while(n%i==0){
				++cnt[pcnt];
				n/=i;
			}
		}
	}
	if(n>1){
		prime[++pcnt]=n;
		cnt[pcnt]=1;
	}
}
ll inv[N];
ll f[10010][810];

int main()
{
	cin >> n >> k;
	divide(n);
	for(int i=1;i<=1000;i++){
		inv[i]=qpow(i,mod-2);
	}
	ll ans=1;
	for(int i=1;i<=pcnt;i++){
		int up=cnt[i];
		for(int i=0;i<=up;i++)f[0][i]=0;
		f[0][up]=1;
		for(int i=1;i<=k;i++){
			for(int j=0;j<=up;j++)f[i][j]=0;
			for(int j=0;j<=up;j++){
				for(int p=0;p<=j;p++){
					f[i][p]+=f[i-1][j]*inv[j+1]%mod;
					f[i][p]%=mod;
				}
			}
		}
		ll R=0;
		ll t=1;
		for(int j=0;j<=up;j++,t=t*(prime[i]%mod)%mod){
			R+=t*f[k][j]%mod;
			R%=mod;
		}
		ans=ans*R%mod;
	}
	cout<<ans<<endl;
}
#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,k,x;
int kpow(int x,int y,int rex=1){
    for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)rex=1ll*rex*x%mod;
    return rex;
}
void work(){
	cin>>n>>k>>x;
	int t=kpow(2,n+1);
	if(x){
		int rex=1,p=2,ans=1;
		for(int i=2,la=1;i<=k;++i,p=2ll*p%mod){
			rex=1ll*rex*t%mod;
			ans=(rex-1ll*la*(p-1)%mod+mod)%mod;
			la=ans;
		}
		cout<<ans<<"\n";
	}
	else{
		if(n>k){
			cout<<0<<"\n";
		}
		else{
			int ans=1,rex=1,ma=kpow(2,k);
			for(int i=1,p=1;i<=n;++i,p=2ll*p%mod){
				rex=(ma+mod-p)%mod;
				ans=1ll*ans*rex%mod;
			}
			cout<<ans<<"\n";
		}
	}
}
int main(){
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}
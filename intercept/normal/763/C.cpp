#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
#define ll long long
using namespace std;
const int M=1e5+9;
int n,mod;
int a[M];
int kpow(int x,int y,int rex=1){
    for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)rex=1ll*rex*x%mod;
    return rex;
}
bool check(int x,int d){
	if(d==0)return n==1;
	int invd=kpow(d,mod-2);
	for(int i=1;i<=n;++i){
		if(1ll*(a[i]+mod-x)*invd%mod>=n)return 0;
	}
	return 1;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>mod>>n;
	int sum=0,sum2=0;
	for(int i=1;i<=n;++i)cin>>a[i],sum=(a[i]+sum)%mod,sum2=(sum2+1ll*a[i]*a[i]%mod)%mod;
	if(n==mod){
		cout<<"0 1\n";
		return 0;
	}
	for(int i=1;i<=n;++i){
		int d=(sum+mod-1ll*a[i]*n%mod)%mod;
		d=2ll*d*kpow(n,mod-2)%mod*kpow(n-1,mod-2)%mod;
		int s2=1ll*a[i]*a[i]%mod*n%mod;
		s2=(s2+1ll*(n-1)*n%mod*a[i]%mod*d%mod)%mod;
		s2=(s2+1ll*(2*n-1)*n%mod*(n-1)%mod*d%mod*d%mod*kpow(6,mod-2))%mod;
		if(s2==sum2&&check(a[i],d)){
			cout<<a[i]<<" "<<d<<endl;
			return 0;
		}
	}
	cout<<"-1\n";
	return 0;
}
#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int mod=998244353;
const int M=20000009;
int n,m,x,y,k;
int a,f[M],g[M];
int main(){
	cin>>n>>a>>x>>y>>k>>m;
	int lc=1,o=1;
	for(int i=1;i<k;++i)lc=lc*i/__gcd(lc,i);
	for(int i=k,o=1;i>=1;--i){
		for(int j=lc-1;j>=0;--j){
			f[j]=(1ll*f[j]*(n-1)%mod+f[j/i*i]+1ll*j*o%mod)%mod;
		}
		o=1ll*o*n%mod;
	}
	o=k;
	for(int i=1;i<k;++i)o=1ll*o*n%mod;
	int ans=0;
	for(int i=0;i<n;++i){
		ans=(1ll*ans+f[a%lc]+1ll*(a/lc*lc)*o%mod)%mod;
		a=(1ll*a*x+y)%m;
	} 
	cout<<ans<<endl;
	return 0;
}
/*
8 10
1 3 2 7 8 2 5 4 6 1
*/
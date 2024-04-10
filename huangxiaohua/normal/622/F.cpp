#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#pragma optimize(2)
#pragma optimize(3)
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define M 1000000007

 
ll ksm(ll a,ll p){ll res=1;while(p){if(p&1){res=res*a%M;}p>>=1;a=a*a%M;}return res;}
 
int i,j,k;
ll n,a[1005000],jc=1,tmp=1,res;
int main(){
	scanf("%lld%d",&n,&k);
	for(i=1;i<=k+2;i++){
		tmp=tmp*(n-i)%M;
		if(i!=k+2){jc=jc*-i%M;}
		a[i]=(ksm(i,k)+a[i-1])%M;
	}
	if(n<=k+2){printf("%lld",a[n]);return 0;}
	
	for(i=1;i<=k+2;i++){
		res+=tmp*ksm((n-i)*jc%M,M-2)%M*a[i]%M;res%=M;
		jc=-jc*i%M*ksm(k+2-i,M-2)%M;
	}
	res=(res%M+M)%M;
	printf("%lld",res);
}
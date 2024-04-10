#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int M=2e5+9;
int n,k,m;
int pw[M];
int main(){
	scanf("%d",&n);
	pw[0]=1; 
	for(int i=1;i<=n;++i)pw[i]=10ll*pw[i-1]%mod;
	for(int i=1;i<=n;++i)printf("%d ",(1ll*pw[n-i+1]*(n-i+1)%mod-(i<n?2ll*pw[n-i]*(n-i)%mod:0)+(i<n-1?1ll*pw[n-i-1]*(n-i-1)%mod:0)+mod)%mod);
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int M=2e5+9;
int n,m;
int d[M],pre[M];
int inv(int x,int y,int rex=1){
	y-=2;
	for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)rex=1ll*rex*x%mod;
	return rex;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&d[i]);
	sort(d+1,d+n+1);
	for(int i=1;i<=n;++i)pre[i]=(pre[i-1]+d[i])%mod;
	for(int i=1,a,b;i<=m;++i){
		scanf("%d%d",&a,&b);
		int x=n+1-(lower_bound(d+1,d+n+1,b)-d),ans=0;
		if(x>=a){
			ans=(ans+1ll*(pre[n]-pre[n-x])*(x-a)%mod*inv(x,mod)%mod)%mod;
			ans=(ans+1ll*pre[n-x]*(x-a+1)%mod*inv(x+1,mod)%mod)%mod;
		}
		printf("%d\n",(ans+mod)%mod);
	} 
	return 0;
}
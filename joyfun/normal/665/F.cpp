#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll f[340000],g[340000],n,k;//f[i] means pi(n/i),g[i] means pi(i)
ll dp(ll n){
	ll i,j,m,res=0;
	for(m=1;m*m<=n;++m)f[m]=n/m-1;
	for(i=1;i<=m;++i)g[i]=i-1;
	for(i=2;i<=m;++i){
		if(g[i]==g[i-1])continue;
		for(j=1;j<=min(m-1,n/i/i);++j){
			if(i*j<m)f[j]-=f[i*j]-g[i-1];
			else f[j]-=g[n/i/j]-g[i-1];
		}
		for(j=m;j>=i*i;--j)g[j]-=g[j/i]-g[i-1];
	}
	for(i=2;i<m;++i){
		if(g[i]==g[i-1])continue;
		res+=f[i]-g[i];
	}return res;
}
int main(){
	scanf("%I64d",&n);k=pow(n,1.0/3)+1e-9;
	printf("%I64d\n",dp(n)+g[k]);
}
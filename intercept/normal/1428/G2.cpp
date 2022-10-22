#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=1e6+9;
const int N=1e6;
int k,q,n;
ll dp[M];
void push(ll w,ll v){
	for(int j=N;j>=w;--j)
		dp[j]=max(dp[j],dp[j-w]+v);
}
int main(){
	for(int i=1;i<=N;++i)dp[i]=-(1ll<<60);
	scanf("%d",&k);
	k=3*(k-1);
	for(int t=0,x,p=1;t<6;++t,p*=10){
		scanf("%d",&x);
		for(int z=1,l=k;z<=N&&l;z<<=1){ 
			if(l>=z)push(3ll*z*p,1ll*z*x),l-=z;
			else push(3ll*l*p,1ll*l*x),l=0;
		}
		for(int j=N;j>=0;--j){
			for(ll g=1;g<=9;++g){
				ll w=g*p,v=(g%3)?0:g/3*x;
				if(j>=w)dp[j]=max(dp[j],dp[j-w]+v);
			}
		}
	}
	scanf("%d",&q);
	for(int i=1;i<=q;++i){
		scanf("%d",&n);
		printf("%lld\n",dp[n]);
	}
	return 0;
}
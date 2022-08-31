#include<bits/stdc++.h>
using namespace std;
const int P=1e9+7,K=5e3+5;
int stirling[K][K];
int n,k,ans;
int pow(int a,int b){
	int ans=1;
	while(b){
		if(b&1){
			ans=1ll*ans*a%P;
		}
		a=1ll*a*a%P;
		b>>=1;
	}
	return ans;
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=0;i<=k;++i){
		stirling[i][i]=1;
		for(int j=1;j<=i-1;++j){
			stirling[i][j]=(stirling[i-1][j-1]+1ll*j*stirling[i-1][j])%P;
		}
	}
	for(int i=0,d=1;i<=k;++i){
		ans=(ans+1ll*stirling[k][i]*d%P*pow(2,n-i+P-1))%P;
		d=1ll*d*(n-i)%P;
	}
	printf("%d\n",ans);
	return 0;
}
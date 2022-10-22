#include<bits/stdc++.h>
#define bco __builtin_popcount 
using namespace std;
const int S=1<<24;
int n,ans,dp[S];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		char c[5];
		int x=0;
		scanf("%s",c);
		for(int j=0;j<3;++j){
			if(c[j]-'a'<24)x|=1<<(c[j]-'a');
		}
		for(int j=x;j;j=x&(j-1))if(j)dp[j]+=(bco(j)&1)?1:-1;
	}
	for(int i=0;i<24;++i){
		for(int s=0;s<S;++s){
			if(!((1<<i)&s))dp[s^(1<<i)]+=dp[s];
		}
	}
	for(int s=0;s<S;++s)ans^=dp[s]*dp[s];
	printf("%d\n",ans);
	return 0;
}
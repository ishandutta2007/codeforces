#include<bits/stdc++.h>
using namespace std;
const int M=5e5+9;
int n;
int c[M],en[M],dp[M],cnt[M],suf[M],in[M];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&c[i]);
		if(!en[c[i]])in[i]=1;
		en[c[i]]=i;
		cnt[c[i]]++;
	}
	for(int i=n;i>=1;--i){
		dp[i]=dp[i+1];
		if(in[i])dp[i]=max(dp[i],cnt[c[i]]+dp[en[c[i]]+1]);
		suf[c[i]]++;
		dp[i]=max(dp[i],suf[c[i]]);
	}
	printf("%d",n-dp[1]);
	return 0;
}
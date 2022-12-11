#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,K,a[1100000],x[1100000],dp[2][1100000],ans;
long long l;
const int mo=1e9+7;
int compare(int k1,int k2){
	return a[k1]<a[k2];
}
int calc(int K,int now){
	int len=(l/n)%mo; int ans=0;
	if (l/n+1>=K)
		for (int i=1;i<=l%n;i++) ans=(ans+1ll*dp[now][i]*(len-K+2))%mo;
	if (l/n>=K)
		for (int i=l%n+1;i<=n;i++) ans=(ans+1ll*dp[now][i]*(len-K+1))%mo;
	return ans;
}
int main(){
	scanf("%d%I64d%d",&n,&l,&K);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) x[i]=i;
	sort(x+1,x+n+1,compare);
	int now=0;
	for (int i=1;i<=n;i++) dp[0][i]=1;
	ans=(ans+calc(1,0))%mo; //cout<<ans<<" "<<K<<endl;
	for (int i=2;i<=K;i++){
		int ne=(now^1);
		for (int j=1;j<=n;j++) dp[ne][j]=0;
		int pre=1,tot=dp[now][x[1]];
		for (int j=2;j<=n+1;j++){
			if (j>n||a[x[j]]!=a[x[pre]]){
				for (int k=pre;k<j;k++) dp[ne][x[k]]=tot;
				pre=j;
			}
			tot=(tot+dp[now][x[j]])%mo;
		}
		now^=1;
		ans=(ans+calc(i,now))%mo;
	//	for (int i=1;i<=n;i++) cout<<dp[ne][i]<<" "; cout<<endl;
	//	cout<<ans<<endl;
	}
	printf("%d\n",(ans+mo)%mo);
	return 0;
}
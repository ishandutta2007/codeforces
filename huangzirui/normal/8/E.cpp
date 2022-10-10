#include <bits/stdc++.h>
#define ll long long
#define Mid ((L+R)>>1)
using namespace std;
typedef pair<int,int> pii;
inline ll read(){
	char c;ll x=0;int b=1;do{c=getchar();if(c==45)b=-1;}while(c>57||c<48);
	do x=x*10+c-48,c=getchar();while(c<=57&&c>=48);x*=b;return x;
}
ll i,j,k,n,m,dp[55][2][2],No[55];
ll dfs(int now,int is1,int is2){
	//cout<<"dfs "<<now<<' '<<is1<<' '<<is2<<endl;
	if(dp[now][is1][is2]!=-1)return dp[now][is1][is2];
	if(now*2>n){
		if(n&1)return 1*(No[now]!=0)+is2*(No[now]!=1);
		return 1;
	}int s[2];
	dp[now][is1][is2]=0;
	for(s[0]=0;s[0]<=1;s[0]++)
		for(s[1]=0;s[1]<=1;s[1]++){
			int Is1=is1,Is2=is2;
			if(No[now]==s[0] || No[n-now+1]==s[1])continue;
			if(now==1 && s[0]==1)continue;
			if(!is1 && s[0]>s[1])continue;if(s[0]<s[1])Is1=1;
			if(!is2 && s[0]>1-s[1])continue;if(s[0]<1-s[1])Is2=1;
			dp[now][is1][is2]+=dfs(now+1,Is1,Is2);
		}
	return dfs(now,is1,is2);
}
int main() {
	cin>>n>>k;k++;
	memset(No,-1,sizeof(No));
	for(i=1;i<=n;i++){
		memset(dp,-1,sizeof(dp));
		No[i]=1;
		dfs(1,0,0);
		if(dp[1][0][0]<k)No[i]=0,k-=dp[1][0][0];
		//cout<<"i="<<i<<" s="<<dp[1][0][0]<<' '<<k<<' '<<1-No[i]<<endl;
	}memset(dp,-1,sizeof(dp));
	if(k==dfs(1,0,0))for(i=1;i<=n;i++)printf("%d",1-No[i]);
	else puts("-1");
	return 0;
}
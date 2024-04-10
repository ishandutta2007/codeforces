#include<bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define ll long long
using namespace std;
const int M=5009;
int n;
int a[M],dp[M],vis[M][M],cnt[M];
void work(){
	int ans=0;
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)cnt[j]=0;
		int mx=0;
		for(int j=i;j>=1;--j){
			mx=max(mx,++cnt[a[j]]);
			int x=(i-j+1);
			if(x%2==0&&mx<=x/2)vis[j][i]=0;
			else vis[j][i]=1;
		}
	}
	for(int o=1;o<=n;++o){
		dp[o]=-n;
		for(int i=o-1;i>=0;--i){
			if((i==0||a[i]==a[o])&&!vis[i+1][o-1])dp[o]=max(dp[o],dp[i]+1);
		}
		if(!vis[o+1][n])ans=max(ans,dp[o]);
	}
	cout<<ans<<endl;
}
int main(){
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}
/*
1
6
1 1 1 2 2 2
*/
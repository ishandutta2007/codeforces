#include<bits/stdc++.h>
using namespace std;
#define N 5005
#define mod 1000000007
int T,n,i,j,ans[N],qwq,a[N],c[N][N],dp[N][N];
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(i=1;i<=n;++i){
			cin>>a[i];
			++c[a[i]][i];
		}
		for(i=1;i<=n;++i){
			for(j=1;j<=n;++j){
				c[i][j]+=c[i][j-1];
			}
		}
		for(i=1;i<=n;++i){
			dp[i][i]=1;
			for(j=i+1;j<=n;++j){
				dp[i][j]=max(dp[i][j-1],c[a[j]][j]-c[a[j]][i-1]);
			}
		}
		for(i=1;i<=n;++i){
			ans[i]=-1e9;
			if(i==1||a[i-1]==a[i])ans[i]=max(ans[i-1]+1,ans[i]);
			for(j=1;j<i;++j){
				if(dp[j][i-1]<=(i-j)/2&&((i-j)&1)==0&&(a[j-1]==a[i]||j==1))
					ans[i]=max(ans[i],ans[j-1]+1);
			}
		}
		qwq=0;
		for(i=1;i<=n;++i){
			qwq=max(qwq,ans[i]-max(dp[i+1][n]*2-(n-i),(dp[i+1][n]*2-(n-i))&1));
		}
		cout<<qwq<<"\n\n";
		for(i=1;i<=n;++i){
			for(j=1;j<=n;++j){
				c[i][j]=dp[i][j]=0;
			}
		}
	} 
}
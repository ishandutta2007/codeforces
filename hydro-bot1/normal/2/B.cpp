// Hydro submission #61f5392837cee20376bd232a@1643460905066
#include<bits/stdc++.h>
using namespace std;
const int maxn=1010;
//dp[i][j][0]:ij2
//dp[i][j][1]:ij5
int dp[maxn][maxn][2];
int main(){
	int n;
	scanf("%d",&n);
	int pos=-1;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int x;
			scanf("%d",&x);
			if(!x){
				pos=i;
				continue;
			}
			//25 
			int y=x;
			while(!(x&1)){
				dp[i][j][0]++;
				x>>=1;
			}
			while(y%5==0){
				dp[i][j][1]++;
				y/=5;
			}
		}
	}
	// 
	for(int i=1;i<n;i++){
		dp[i][0][0]+=dp[i-1][0][0];
		dp[i][0][1]+=dp[i-1][0][1];
		
		dp[0][i][0]+=dp[0][i-1][0];
		dp[0][i][1]+=dp[0][i-1][1];
	}
	//ij(i-1)j()i(j-1)() 
	//25 
	for(int i=1;i<n;i++){
		for(int j=1;j<n;j++){
			dp[i][j][0]+=min(dp[i-1][j][0],dp[i][j-1][0]);
			dp[i][j][1]+=min(dp[i-1][j][1],dp[i][j-1][1]);
		}
	}
	string ans;
	//25 
	int res=dp[n-1][n-1][0]>dp[n-1][n-1][1]?1:0;
	//0 
	if(pos!=-1 && dp[n-1][n-1][res]>0){
		printf("1\n");
		for(int i=0;i<pos;i++) printf("D");
		for(int i=1;i<n;i++) printf("R");
		for(int i=pos;i<n-1;i++) printf("D");
		return 0;
	}
	int i=n-1,j=n-1;
	// 
	// 
	while(1){
		if(dp[i-1][j][res]<dp[i][j-1][res]){
			i--;
			ans+="D";
		}else{
			j--;
			ans+="R";
		}
		// 
		if(i==0){
			for(int x=0;x<j;x++) ans+="R";
			break;
		}
		if(j==0){
			for(int x=0;x<i;x++) ans+="D";
			break;
		}
	}
	printf("%d\n",dp[n-1][n-1][res]);
	for(int i=ans.size()-1;i>-1;i--) printf("%c",ans[i]);
	return 0;
}
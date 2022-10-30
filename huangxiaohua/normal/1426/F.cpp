#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
 
int i,j,t,n;
ll tmp,dp[200500][3],res,p=1;
char sb[200500];
int main(){
	scanf("%d",&n);getchar();
	gets(sb+1);
	for(i=1;i<=n;i++){
		if(sb[i]=='c'){
			res+=dp[i-1][2];res%=M;
			dp[i][2]=dp[i-1][2];
			dp[i][1]=dp[i-1][1];
		}
		if(sb[i]=='b'){
			dp[i][2]=dp[i-1][2]+dp[i-1][1];dp[i][2]%=M;
			dp[i][1]=dp[i-1][1];
		}
		if(sb[i]=='a'){
			dp[i][2]=dp[i-1][2];
			dp[i][1]=dp[i-1][1]+p;dp[i][1]%=M;
		}
		if(sb[i]=='?'){
			res=res*3+dp[i-1][2];res%=M;
			dp[i][2]=dp[i-1][2]*3+dp[i-1][1];dp[i][2]%=M;
			dp[i][1]=dp[i-1][1]*3+p;dp[i][1]%=M;
			p=p*3%M;
		}
	}
	printf("%lld\n",res);
}
#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int dp[77][1<<20];
const int M=20;
char ch[1100];
int A[1100],n,pd[1100],bo[1<<20];
const int mo=1e9+7;
void update(int &k1,int k2){
	k1=(k1+k2)%mo;
}
int main(){
	scanf("%d",&n);
	scanf("%s",ch+1);
	for (int i=0;i<=M;i++) bo[(1<<i)-1]=1;
	for (int i=1;i<=n;i++) A[i]=ch[i]-'0';
	for (int i=n;i&&A[i]==0;i--) pd[i]=1;
	dp[0][0]=1; int now=0;
	int ans=0;
	for (int i=1;i<=n;i++) dp[i][0]=1;
	for (int i=0;i<n;i++){
		if (A[i+1]==0){
			if (pd[i]) continue;
			for (int j=0;j<(1<<M);j++) update(dp[i+1][j],dp[i][j]);
		} else {
			int pre=A[i+1];
			for (int j=i+1;j<=n&&pre<=M;j++){
				for (int k=0;k<(1<<M);k++){
					int k1=k|(1<<pre-1);
					update(dp[j][k1],dp[i][k]);
					if (bo[k1]){
					//	if (k1==0) cout<<"fa "<<endl;
						update(ans,dp[i][k]);
					}
				}
				pre=(pre<<1)+A[j+1];
			}
		}
	//	for (int j=0;j<5;j++) cout<<dp[i][j]<<" "; cout<<endl;
	}
//	int ans=0;
//	for (int i=1;i<=M;i++) ans=(ans+dp[n][(1<<i)-1])%mo;
	cout<<ans<<endl;
}
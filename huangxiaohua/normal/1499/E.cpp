#include <bits/stdc++.h>
using namespace std;
#define M 998244353
int i,j,k,n,m,dp[1050][1050][27],dp2[2][1050][30],res,tmp;
char a[1050],b[1050];
int su(int a,int b){a+=b;if(a>=M){a-=M;}return a;}
int main(){
	cin>>a+1>>b+1;
	n=strlen(a+1);m=strlen(b+1);
	for(i=1;i<=n;i++){a[i]-=('a'-1);for(j=1;j<=26;j++){if(j!=a[i]){dp2[0][i][a[i]]+=dp2[0][i-1][j];}}dp2[0][i][a[i]]++;}
	for(i=1;i<=m;i++){b[i]-=('a'-1);for(j=1;j<=26;j++){if(j!=b[i]){dp2[1][i][b[i]]+=dp2[1][i-1][j];}}dp2[1][i][b[i]]++;}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			for(k=1;k<=26;k++){
				if(k!=a[i]){dp[i][j][a[i]]=su(dp[i][j][a[i]],su(dp[i-1][j][k],dp2[1][j][k]));}
				if(k!=b[j]){dp[i][j][b[j]]=su(dp[i][j][b[j]],su(dp[i][j-1][k],dp2[0][i][k]));}
			}
			res=su(res,dp[i][j][a[i]]);
			if(a[i]!=b[j]){res=su(res,dp[i][j][b[j]]);}
		}
	}
	cout<<su(res,M-tmp);
}
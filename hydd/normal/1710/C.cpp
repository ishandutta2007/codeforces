#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353;
int n,p[210000],dp[210000][2][2][2][2][2][2]; string s;
int solve(int len,int a,int b,int c,int x,int y,int z){
	if (len==n+1) return x&&y&&z;
	if (dp[len][a][b][c][x][y][z]!=-1) return dp[len][a][b][c][x][y][z]; 
	dp[len][a][b][c][x][y][z]=0;
	for (int i=0;i<=(a?p[len]:1);i++)
		for (int j=0;j<=(b?p[len]:1);j++)
			for (int k=0;k<=(c?p[len]:1);k++){
				int t1=(i^j)+(j^k)-(i^k),t2=(i^j)+(i^k)-(j^k),t3=(j^k)+(i^k)-(i^j);
				if (!x&&t1<0||!y&&t2<0||!z&&t3<0) continue;
				dp[len][a][b][c][x][y][z]=(dp[len][a][b][c][x][y][z]+solve(len+1,a&&(i==p[len]),b&&(j==p[len]),c&&(k==p[len]),x||(t1>0),y||(t2>0),z||(t3>0)))%Mod;
			}
	return dp[len][a][b][c][x][y][z];
}
int main(){
	memset(dp,-1,sizeof(dp));
	cin>>s; n=s.length();
	for (int i=1;i<=n;i++) p[i]=s[i-1]-'0';
	cout<<solve(1,1,1,1,0,0,0)<<endl;
	return 0;
}
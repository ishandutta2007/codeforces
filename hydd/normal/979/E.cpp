#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Mod=1e9+7;
int n,p,c[55];
int pw[55],dp[55][55][55][55];
int add(int x,int y){
	return (x+y>=Mod?x+y-Mod:x+y);
}
int main(){
	scanf("%d%d",&n,&p); pw[0]=1;
	for (int i=1;i<=n;i++) pw[i]=add(pw[i-1],pw[i-1]);
	for (int i=1;i<=n;i++) scanf("%d",&c[i]);
	dp[0][0][0][0]=1; int ans=0;
	for (int s=0;s<=n;s++)
		for (int i=0;i<=s;i++)//0 odd
			for (int j=0;i+j<=s;j++)//0 even
				for (int x=0;i+j+x<=s;x++){//1 odd
					int y=s-(i+j+x);//1 even
					ll v=dp[i][j][x][y]; if (!v) continue;
					if (s==n){
						if (((i+x)&1)==p) ans=add(ans,v);
						continue;
					}
					if (c[s+1]!=1){//0
						if (x){
							int tmp=v*pw[i+j+y+x-1]%Mod;
							dp[i+1][j][x][y]=add(dp[i+1][j][x][y],tmp);
							dp[i][j+1][x][y]=add(dp[i][j+1][x][y],tmp);
						} else{
							int tmp=v*pw[i+j+y]%Mod;
							dp[i+1][j][x][y]=add(dp[i+1][j][x][y],tmp);
						}
					}
					if (c[s+1]!=0){//1
						if (i){
							int tmp=v*pw[x+y+j+i-1]%Mod;
							dp[i][j][x+1][y]=add(dp[i][j][x+1][y],tmp);
							dp[i][j][x][y+1]=add(dp[i][j][x][y+1],tmp);
						} else{
							int tmp=v*pw[x+y+j+i]%Mod;
							dp[i][j][x+1][y]=add(dp[i][j][x+1][y],tmp);
						}
					}
				}
	printf("%d\n",ans);
	return 0;
}
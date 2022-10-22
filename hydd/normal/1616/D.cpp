#include<bits/stdc++.h>
using namespace std;
int T,n,a[51000],v,dp[51000][2][2];
bool check(int i,int x,int y,int z){
	return !(x&&y&&z)||(a[i-1]+a[i]+a[i+1]>=0);
}
bool check(int i,int y,int z){
	return !(y&&z)||(a[i]+a[i+1]>=0);
}
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		scanf("%d",&v);
		if (n==1){
			puts("1");
			continue;
		}
		for (int i=1;i<=n;i++) a[i]-=v;
		memset(dp,0,sizeof(dp));
		for (int x=0;x<=1;x++)
			for (int y=0;y<=1;y++)
				if (check(1,x,y)) dp[2][x][y]=x+y;
		for (int i=2;i<n;i++)
			for (int x=0;x<=1;x++)
				for (int y=0;y<=1;y++)
					for (int z=0;z<=1;z++)
						if (check(i,x,y,z)&&check(i,y,z)) dp[i+1][y][z]=max(dp[i+1][y][z],dp[i][x][y]+z);
		int ans=0;
		for (int x=0;x<=1;x++)
			for (int y=0;y<=1;y++)
				ans=max(ans,dp[n][x][y]);
		printf("%d\n",ans);
	}
	return 0;
}
#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int A[1100][1100],dp[1100][1100],n,m,B[1100][1100],lo[1100];
short f[1100][1100][10][10];
int get(int k1,int k2,int k3,int k4){
	int a=lo[k3-k1+1],b=lo[k4-k2+1];
//	cout<<"ask "<<k1<<" "<<k2<<" "<<k3<<" "<<k4<<" "<<a<<" "<<b<<" ";
	k1+=(1<<a)-1; k2+=(1<<b)-1;
//	cout<<max(max(f[k3][k4][a][b],f[k1][k2][a][b]),max(f[k1][k4][a][b],f[k3][k2][a][b]))<<endl;
	return max(max(f[k3][k4][a][b],f[k1][k2][a][b]),max(f[k1][k4][a][b],f[k3][k2][a][b]));
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) scanf("%d",&A[i][j]);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) B[i][j]=A[i][j]+B[i-1][j]+B[i][j-1]-B[i-1][j-1];
//	cout<<A[1][1]<<endl;
	memset(dp,0x00,sizeof dp);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++){
			if (A[i][j]==0){
				dp[i][j]=0; continue;
			}
			int l=1,r=min(i,j)+1,ans=0;
			while (l<r){
				int mid=l+r>>1;
				if (B[i][j]+B[i-mid][j-mid]-B[i][j-mid]-B[i-mid][j]==mid*mid){
					ans=mid; l=mid+1;
				} else r=mid;
			}
			dp[i][j]=ans;
		}
	for (int i=1;i<=max(n,m);i++) lo[i]=trunc(log2(i)+1e-8);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			f[i][j][0][0]=dp[i][j];
//	for (int i=1;i<=n;i++){
//		for (int j=1;j<=m;j++) cout<<dp[i][j]<<" "; cout<<endl;}
	for (int a=1;a<10;a++)
		for (int i=(1<<a);i<=n;i++)
			for (int j=1;j<=m;j++)
				f[i][j][a][0]=max(f[i][j][a-1][0],f[i-(1<<a-1)][j][a-1][0]);
	for (int b=1;b<10;b++)
		for (int a=0;a<10;a++)
			for (int i=(1<<a);i<=n;i++)
				for (int j=(1<<b);j<=m;j++)
					f[i][j][a][b]=max(f[i][j][a][b-1],f[i][j-(1<<b-1)][a][b-1]);
	int q; scanf("%d",&q);
	for (;q;q--){
		int x1,y1,x2,y2; scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		int l=1,r=min(x2-x1+1,y2-y1+1)+1,ans=0;
		while (l<r){
			int mid=l+r>>1;
			if (get(x1+mid-1,y1+mid-1,x2,y2)>=mid){
				ans=mid; l=mid+1;
			} else r=mid;
		}
		printf("%d\n",ans);
	}
	return 0;
}
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,m,k;
int a[1005][1005];
ll up[1005][1005];
ll lef[1005][1005];
ll rig[1005][1005];
ll val[1005][1005]={0};
ll fl(int i,int j){
	return lef[i][j]-lef[i+k][j-k]-rig[i+k][j-k+1]+rig[i+2*k][j+1];
}
ll fr(int i,int j){
	return rig[i][j]-rig[i+k][j+k]-lef[i+k][j+k-1]+lef[i+2*k][j-1];
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)scanf("%d",&a[i][j]);
	for (int i=n;i>=1;i--)
		for (int j=1;j<=m;j++)up[i][j]=up[i+1][j]+a[i][j];
	for (int j=1;j<=m;j++)
		for (int i=n;i>=1;i--)lef[i][j]=lef[i+1][j-1]+up[i][j];
	for (int j=m;j>=1;j--)
		for (int i=n;i>=1;i--)rig[i][j]=rig[i+1][j+1]+up[i][j];
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)val[k][k]+=a[i][j]*max(0,k-abs(i-k)-abs(j-k));
	int a=k,b=k;
	for (int i=k;i<=n-k+1;i++)
		for (int j=k;j<=m-k+1;j++){
			if(i==k && j==k)continue;
			if(j!=k){
				val[i][j]=val[i][j-1]-fl(i-k+1,j-1)+fr(i-k+1,j);
			}else{
				val[i][j]=val[i-1][j];
				for (int l=1;l<=k;l++){
					val[i][j]-=(up[i-l][j-k+l]-up[i][j-k+l]);
					val[i][j]+=(up[i][j-k+l]-up[i+l][j-k+l]);
				}
				for (int l=k-1;l>=1;l--){
					val[i][j]-=(up[i-l][j+k-l]-up[i][j+k-l]);
					val[i][j]+=(up[i][j+k-l]-up[i+l][j+k-l]);
				}
			}
			if(val[i][j]>val[a][b])a=i,b=j;
		}
	printf("%d %d\n",a,b);
	return 0;
}
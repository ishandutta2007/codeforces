#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
int mx=0,dp1[1001][1001],dp2[1001][1001],dp3[1001][1001],dp4[1001][1001],n,m,a[1001][1001];
int dpp1(int x,int y){
	if(dp1[x][y]>0) return dp1[x][y];
	int ans=0;
	if(x>0) ans=dpp1(x-1,y);
	if(y>0) ans=max(dpp1(x,y-1),ans);
	dp1[x][y]=ans+a[x][y];
	return ans+a[x][y];
}
int dpp2(int x,int y){
	if(dp2[x][y]>0) return dp2[x][y];
	int ans=0;
	if(x<n-1) ans=dpp2(x+1,y);
	if(y<m-1) ans=max(dpp2(x,y+1),ans);
	dp2[x][y]=ans+a[x][y];
	return ans+a[x][y];
}
int dpp3(int x,int y){
	if(dp3[x][y]>0) return dp3[x][y];
	int ans=0;
	if(x>0) ans=dpp3(x-1,y);
	if(y<m-1) ans=max(dpp3(x,y+1),ans);
	dp3[x][y]=ans+a[x][y];
	return ans+a[x][y];
}
int dpp4(int x,int y){
	if(dp4[x][y]>0) return dp4[x][y];
	int ans=0;
	if(x<n-1) ans=dpp4(x+1,y);
	if(y>0) ans=max(dpp4(x,y-1),ans);
	dp4[x][y]=ans+a[x][y];
	return ans+a[x][y];
}
int main(){
	cin>>n>>m;
	f(i,0,n){
		f(j,0,m)
			cin>>a[i][j];
	}
	dpp1(n-1,m-1);
	dpp2(0,0);
	dpp3(n-1,0);
	dpp4(0,m-1);
	f(i,1,n-1){
		f(j,1,m-1){
			mx=max(mx,dp4[i][j-1]+dp3[i][j+1]+dp1[i-1][j]+dp2[i+1][j]);
			mx=max(mx,dp4[i+1][j]+dp3[i-1][j]+dp1[i][j-1]+dp2[i][j+1]);
		}
	}
	cout<<mx;
}
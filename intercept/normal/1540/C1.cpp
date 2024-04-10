#include<bits/stdc++.h>
#define pii pair<int,int>
#define eb emplace_back
#define fi first
#define se second
#define ll long long
using namespace std;
const int mod=1e9+7;
const int M=209;
int n,q;
int c[M],b[M],a[M],dp[M][M*M];
int main(){
	cin>>n;
	for(int i=1;i<=n;++i)cin>>c[i];
	for(int i=1;i<n;++i)cin>>b[i];
	cin>>q;
	int x;
	cin>>a[1];
	for(int i=2;i<=n;++i)a[i]=a[i-1]+b[i-1];
	int l=0,r=0;
	dp[0][0]=1;
	for(int i=1;i<=n;++i){
		int L=l-a[i],R=r+c[i]-a[i];
		for(int j=0;j<=c[i];++j){
			int t=j-a[i];
			for(int k=L;k<=R;++k){
				if(k-t>=0&&k-t<=r)dp[i][k-L]=(dp[i][k-L]+dp[i-1][k-t-l])%mod;
			}
		}
		l=L,r=R;
	}
	for(int i=r-1;i>=l;--i)dp[n][i-l]=(dp[n][i-l]+dp[n][i+1-l])%mod;
	if(0>r)puts("0");
	else cout<<dp[n][max(0,-l)];
	// for(int i=1;i<=q;++i){
	// 	int x;
	// 	cin>>x;
	// 	int d=(x+0)*n;
	// 	if(d>r)puts("0");
	// 	else if(d<l)printf("%d\n",dp[n][0]);
	// 	else printf("%d\n",dp[n][d-l]);
	// }
	return 0;
}
/*
3
2 3 4
2 1
1
-1
*/
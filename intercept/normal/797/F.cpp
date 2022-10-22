#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
#define ll long long
using namespace std;
const int M=5009;
int n,m;
ll dp[M][M],c[M],x[M],p[M],q[M],val[M];
int id[M];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>x[i];
	sort(x+1,x+n+1);
	for(int i=1;i<=m;++i)cin>>p[i]>>c[i],id[i]=i;
	sort(id+1,id+m+1,[&](const int&l,const int&r){return p[l]<p[r];});
	for(int i=0;i<=m;++i){
		for(int j=0;j<=n;++j)dp[i][j]=1ll<<60;
	}
	dp[0][0]=0;
	for(int i=1;i<=m;++i){
		ll sum=0;
		int l=1,r=1;
		dp[i][0]=0;
		q[1]=0;
		for(int j=1;j<=n;++j){
			sum+=abs(x[j]-p[id[i]]);
			while(l<=r&&q[l]<j-c[id[i]])l++;
			while(l<=r&&dp[i-1][j]-sum<val[r])r--;
			q[++r]=j;
			val[r]=dp[i-1][j]-sum;
			dp[i][j]=val[l]+sum;
		}
	}
	if(dp[m][n]==1ll<<60)cout<<"-1\n";
	else cout<<dp[m][n]<<"\n";
	return 0;
}
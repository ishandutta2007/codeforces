#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
using namespace std;
const int M=2009;
int n,k;
ll l[M],r[M],a[M];
ll s[M],dp[M][2];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>l[i]>>r[i]>>a[i];
		s[i]=s[i-1]+a[i];
	}
	for(int i=0;i<=n;++i){
		for(int o=0;o<2;++o)dp[i][o]=1ll<<60;
	}
	dp[0][0]=0;
	ll ans=1ll<<60;
	for(int i=0;i<n;++i){
		for(int o=0;o<2;++o){
			if(dp[i][o]==1ll<<60)continue;
			bool bo=o;
			int x=(bo&&(l[i+1]==r[i]))?0:k;
			for(int j=i+1;j<=n;++j){
				int L=l[j];
				ll y=(a[j]-x-1);
				if(y<0)y=0;
				else y=y/k+1;
				if(L+y>r[j])break;
				if(L+y==r[j]){
					bo=1;
				}
				else bo=0;
				x=y*k-(a[j]-x);
				if(j==n)ans=min(ans,dp[i][o]+s[j]-s[i]);
				dp[j][bo]=min(dp[j][bo],dp[i][o]+s[j]-s[i]+x);
				if(x==0){
					x=(bo&&(l[j+1]==r[j]))?0:k;
				}
			}
		}
	}
	cout<<((ans==1ll<<60)?-1:ans)<<"\n";
	return 0;
}
#include <bits/stdc++.h>

#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii 		vector<pii>
#define mi 			map<int,int>
#define mii			map<int,pii>	
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define hell        1000000000
#define endl        '\n'
#define rep(i,a,b)	for(int i=a;i<b;i++)
using namespace std;
int n,ans=0,o[2002],p[2002],dp[2002][2002];
void solve(){
	cin>>n;
	vi a(n);
	rep(i,0,n){
		cin>>a[i];
		if(a[i]==1) ans++;
		o[i]=(a[i]==1);
		if(i) o[i]+=o[i-1];
	}
	for(int i=n-1;i>=0;i--){
		p[i]=(a[i]==2)+p[i+1];
	}
	ans=max(ans,n-ans);
	rep(i,1,n+1){
		rep(j,0,n){
			if(j+i-1>=n) continue;
			if(i==1) dp[j][j]=1;
			else{
				if(a[j]==1){
					dp[j][j+i-1]=max(dp[j+1][j+i-1],o[j+i-1]-(j?o[j-1]:0));
				}
				else{
					dp[j][j+i-1]=1+dp[j+1][j+i-1];	
				}
			}
		}
	}
	rep(i,0,n){
		rep(j,i,n){
			ans=max(ans,o[i-1]+p[j+1]+dp[i][j]);
		}
	}
	cout<<ans;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--)
		solve();
	return 0;
}
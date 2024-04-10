#include "bits/stdc++.h"

#ifdef PRINTERS
#include "printers.hpp"
using namespace printers;
#define tr(a)		cerr<<#a<<" : "<<a<<endl
#else
#define tr(a)    
#endif

#define ll          long long
#define pb          push_back
#define mp          make_pair
#define pii         pair<int,int>
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define endl        '\n'
#define rep(i,a,b)	for(int i=a;i<b;i++)
using namespace std;

int dp[101][101][101*101];
vi x,y;
void solve(){
	int n;
	cin>>n;
	x.resize(n);
	y.resize(n);
	int S=0;
	rep(i,0,n)cin>>x[i],S+=x[i];
	rep(i,0,n)cin>>y[i];
	vi z=y;
	sort(all(z));
	reverse(all(z));
	int cnt=0;
	int tempS=0;
	rep(i,0,n){
		tempS+=z[i];
		if(tempS>=S){
			cnt=i+1;
			break;
		}
	}
	cout<<cnt<<" ";
	int ans=0;
	rep(i,0,n+1){
		rep(j,0,i+1){
			rep(k,0,10001){
				if(j==0){
					dp[i][j][k]=k?INT_MIN:0;
				}
				else{
					dp[i][j][k]=INT_MIN;
					if(i-1>=j)
						dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]);
					if(k-y[i-1]>=0){
						dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k-y[i-1]]+x[i-1]);
					}
				}
				if(i==n and j==cnt and k>=S){
					ans=max(ans,dp[i][j][k]);
				}
			}
		}
	}
	cout<<S-ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
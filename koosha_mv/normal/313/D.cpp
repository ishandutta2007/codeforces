#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
ll n,m,k,co[302][302],dp[302][302],l,r,c,mx=1e18;
int main(){
	cin>>n>>m>>k;
	f(i,0,302){
		f(j,1,302){
			co[i][j]=1e18;
			dp[i][j]=1e18;
		}
	}
	f(i,0,m){
		cin>>l>>r>>c;
		f(j,l,r+1){
			co[l][j]=min(co[l][j],c);
		}
	}
	f(i,1,n+1){
		f(j,1,k+1){
			f(p,0,i){
				int e=i-p;
				if(j-e>=0)dp[i][j]=min(dp[i][j],dp[p][j-e]+co[p+1][i]);
			}
			dp[i][j]=min(dp[i][j],dp[i-1][j]);
			if(j==k) mx=min(mx,dp[i][j]);
		}
	}
	cout<<mx*(mx<1e17)+-1*(mx>=1e17);
}
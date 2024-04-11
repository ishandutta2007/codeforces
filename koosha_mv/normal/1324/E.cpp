#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define Gett(x,y) scanf("%d%d",&x,&y);
#define gett(x) scanf("%d",&x);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
const int N=3002,mod=1e9+7;
int h,l,r,dp[2][N],x,n,ans;
int main(){
	f(i,1,N) dp[0][i]=-10000;
	cin>>n>>h>>l>>r;
	f(i,1,n+1){
		cin>>x;
		f(j,0,h){
			dp[i%2][j]=max(dp[1-(i%2)][(j+h-x)%h],dp[1-(i%2)][(j+h-x+1)%h])+(j>=l && j<=r);
			maxm(ans,dp[i%2][j]);
		}
	}
	cout<<ans<<endl;
}
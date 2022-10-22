#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=201,mod=1e9+7,mid=50000;
 
int n,k,ans,sum,t,dp[2][N][mid+2003],a[N],can[N][mid+2003];

int sghf(int x,int y){
	if(x>=0) return 0;
	x*=-1;
	return x/y+(x%y>0);
}
int main(){
	cin>>n>>k;
	f(i,1,n+1) cin>>a[i];
	dp[0][0][mid]=1;
	sort(a+1,a+1+n);
	can[0][mid]=1;
	f(i,1,n+1){
		f(j,mid-min(i,n-i)*500,mid+k+1){
			can[i][j]=(can[i-1][j] || can[i-1][j+a[i]]);
			if(j>=a[i]) can[i][j]=(can[i][j] || can[i-1][j-a[i]]);
		}
	}
	
	f(i,1,n+1)
		f(l,mid-min(i,n-i)*500,mid+k+1){
			if(can[i][l]){
				f(j,max(sghf(l-mid,500),0),min(i,n-i)+1){
					bool src=i%2;
					dp[src][j][l]=(1ll*dp[!src][j][l]*j+dp[!src][j][l])%mod;
					dp[src][j][l]=(dp[src][j][l]+1ll*(j+1ll)*dp[!src][j+1][l-a[i]])%mod;	
					if(j) dp[src][j][l]=(dp[src][j][l]+dp[!src][j-1][l+a[i]])%mod;
				}
			}
		}
	f(i,0,k+1) ans=(ans+dp[n%2][0][i+mid])%mod;
	cout<<ans;
	
}
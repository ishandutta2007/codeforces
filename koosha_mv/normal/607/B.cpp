#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
const int N=509;
ll dp[N][N],n,a[N];
string s;
int main(){
	cin>>n;
	f(i,0,n) get(a[i]);
	f(i,0,n) dp[i][i]=1;
	f(i,1,n){
		f_(j,i-1,0){
			dp[j][i]=i-j+1;
  	 		if(a[i]==a[j])
  	 			dp[j][i]=max(dp[j+1][i-1],1ll);
   			f(l,j,i)
   	 			minm(dp[j][i],dp[j][l]+dp[l+1][i]);
  		}
 	}
	cout<<dp[0][n-1];
}
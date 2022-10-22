#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
const int N=5009;
ll dp[N][N],a[N],n,l,r,mid,p,mx;
ll binary_s(ll b,ll x){
	l=0;r=N;
	if(dp[b][0]>x)
		return -1;
	while(l+1<r){
		mid=(l+r)/2;
		if(dp[b][mid]<=x)
			l=mid;
		else
			r=mid;
	}
	return l;
}
int main(){
	cin>>n;
	f(i,1,n+1){cin>>a[i];a[i]+=a[i-1];}
	f(i,0,N){f(j,0,N) dp[i][j]=1e9;}
	dp[0][0]=0;
	f(i,1,n+1){
		f(j,0,i){
			p=binary_s(j,a[i]-a[j]);
			if(p>=0)
				minm(dp[i][p+1],a[i]-a[j]);
		}
		f_(j,i,0){
			minm(dp[i][j],dp[i][j+1]);
			if(i==n && dp[i][j]<1e9)
				maxm(mx,j);
		}
	}
	cout<<n-mx;
}
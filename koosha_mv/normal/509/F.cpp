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
#define add(x,y) x=(x+y)%mod;
#define S second
#define F first

const int N=505,mod=1e9+7;

int n,a[N],dp[N][N];

int pd(int l,int r){
	return max(dp[l+1][r],1);
}
void solve(int l,int r){
	dp[l][r]=max(1,dp[l+1][r]);
	f(i,l,r)
		if(a[l]<a[i+1])
			add(dp[l][r],1ll*pd(l,i)*dp[i+1][r]%mod);
}

int main(){
	cin>>n;
	f(i,1,n+1) cin>>a[i];
	f(r,1,n+1)
		f_(l,r,1)
			solve(l,r);
	cout<<pd(1,n);
}
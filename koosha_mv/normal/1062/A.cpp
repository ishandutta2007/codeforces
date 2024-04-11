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

const int N=5e5+9;

int t,n,a[N],dp[N],ans=1;

int main(){
	cin>>n;
	a[0]=0,a[n+1]=1e3+1;
	f(i,1,n+1)
		cin>>a[i];
	f(i,1,n+2){
		if(a[i]==a[i-1]+1) dp[i]=dp[i-1]+1;
		maxm(ans,dp[i]);
	}
	cout<<ans-1;
}
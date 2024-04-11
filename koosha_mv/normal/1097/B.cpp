#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define bit(x) (1ll<<(x*1ll))
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=5000;
int n,t,a[N],sum,e=360*100,dp[N];

int main(){
	dp[0]=1;
	cin>>n;
	f(i,0,n){
		cin>>a[i];
		sum+=a[i];
		a[i]*=2;
	}
	f(i,0,n){
		f_(j,N-1,a[i])
			dp[j]+=dp[j-a[i]];
	}
	sum+=e;
	f(i,0,N){
		//cout<<i<<" : "<<dp[i]<<endl;
		if(dp[i] && (sum-i)%360==0) return cout<<"YES",0;
	}
	cout<<"NO";
}
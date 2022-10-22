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

const ll N=5005,inf =5005*1e9;

int n,T;
ll dp[N][N],ans;
pair<int,int> a[N];

int main(){
	cin>>T;
	for(;T--;){
		ans=inf;
		cin>>n;
		f(i,1,n+1) cin>>a[i].F>>a[i].S;
		sort(a+1,a+1+n);
		reverse(a+1,a+1+n);
		f(i,1,n+2) dp[0][i]=inf;
		f(i,1,n+1){
			int cost=a[i].F-(n-i);
			f(j,0,n){
				dp[i][j]=inf;
				if(j>0) minm(dp[i][j],dp[i-1][j-1]+a[i].S);
				if(j>=cost) minm(dp[i][j],dp[i-1][j]);
				if(i==n) minm(ans,dp[i][j]);
			}
		}
		cout<<ans<<'\n';
	}
}
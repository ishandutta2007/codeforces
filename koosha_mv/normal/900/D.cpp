#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
ll n,x,y,g,a,b,dp[2003],d[2000],s,ans,mod=1e9+7;
map <ll,ll> tvn2,mark;
ll tvn(ll x){
	if(tvn2[x]>0) return tvn2[x];
	if(x%2==1) tvn2[x]=(tvn(x-1)*2)%mod;
	else{
		ll p=tvn(x/2);
		tvn2[x]=(p*p)%mod;
	}
	return tvn2[x];
}
ll dfs(ll x){
	if(dp[x]>0) return dp[x];
	dp[x]=tvn(d[x]-1);
	f(i,0,x){
		if(d[x]%d[i]==0){
			dp[x]=(dp[x]+mod-dfs(i))%mod;
		}
	}
	return dp[x];
}
int main(){
	tvn2[0]=1,tvn2[1]=2;
	cin>>x>>y;
	if(y%x!=0){cout<<0;return 0;}
	x=y/x;
	f(i,1,1e5){
		if(x%i==0){
			if(mark[i]==0){
				mark[i]=1;
				d[s]=i,s++;
			}
			if(mark[x/i]==0){
				mark[x/i]=1;
				d[s]=x/i,s++;
			}
		}
	}
	sort(d,d+s);
	ans=dfs(s-1);
	cout<<ans;
}
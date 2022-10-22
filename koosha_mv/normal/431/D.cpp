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
ll m,k,dp[70],p,d,ans,l,r=1e18+2,mid;
string s1,s2;
string binary(ll m,ll k){string g="";f(i,0,k){g+=char((m%2)+'0'),m=m/2;}return g;}
bool check(ll x){
	ll cx=x,t=0;d=0,ans=0;
	f(i,0,68) dp[i]=0;
	while(cx){cx/=2;t++;}
	s1=binary(x+1,t);
	f_(i,t-1,0){
		if(s1[i]=='0'){
			f_(j,k,1)
				dp[j]+=dp[j-1];
			dp[d+1]++;
		}
		else{
			f_(j,k,1)
				dp[j]+=dp[j-1];
			d++;
		}
	}
	dp[d]++;
	ans=dp[k];
	s1=binary(2*x,t+1);f(i,0,65) dp[i]=0;
	d=1;
	f_(i,t-1,0){
		if(s1[i]=='0'){
			f_(j,k,1)
				dp[j]+=dp[j-1];
		}
		else{
			f_(j,k,1)
				dp[j]+=dp[j-1];
			dp[d]++;
			d++;
		}
	}
	dp[d]++;
	ll o=0;x++;
	while(x){
		o+=x%2;
		x/=2;
	}
	if(o==1) ans=0;
	return (ans+dp[k]<=m);
}
int main(){
	cin>>m>>k;
	while(l+1<r){
		mid=(l+r)/2;
		if(check(mid))
			l=mid;
		else r=mid;
	}
	cout<<l<<endl;
}
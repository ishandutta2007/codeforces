#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
ll dp[200099],h,g,r,ans,mod=1e9+7;
int main(){
	cin>>g>>r;
	swap(g,r);
	f(i,1,1009){
		if(i*(i+1)/2>g+r){
			h=i-1;break;
		}
	}
	dp[0]=1;
	f(i,1,h+1){
		f_(j,g,i){
			dp[j]=(dp[j]+dp[j-i])%mod;
		}
	}
	f(i,max(h*(h+1)/2-r,(ll)0),g+1){
		ans=(ans+dp[i])%mod;
	}
	cout<<ans;
}
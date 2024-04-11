#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
ll n,x,mx=-(1e9),ans,mn=1e9;
int main(){
	cin>>n;
	f(i,0,n){
		cin>>x;
		ans+=abs(x);
		minm(mn,x);
		maxm(mx,x);
	}
	if(n==1){cout<<x;return 0;}
	if(mx<0) cout<<ans+mx*2;
	else{
		if(mn>=0)
			cout<<ans-mn*2;
		else
			cout<<ans;
	}
}
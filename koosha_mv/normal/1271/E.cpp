#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
ll n,k,tn,cn,tavan[75];
int check(ll x){
	if(x==0) return 1;
	if(x>n) return 0;
	if(x%2==1) x++;
	ll c2x=x,tx=0,ans=0,cx=x,p=0;
	while(cx>0){
		tx++;
		cx/=2;
	}
	f(i,0,tn-tx+1){
		ans+=max(min(tavan[i+1],n-x+1),(ll)0);
		x*=2;
	}
	if(ans>=k) return 1;
	else return 0;
}
int check1(ll x){
	if(x>n) return 0;
	ll c2x=x,tx=0,ans=0,cx=x,p=0;
	while(cx>0){
		tx++;
		cx/=2;
	}
	f(i,0,tn-tx+1){
		if(c2x%2==0)
			ans+=max(min(tavan[i+1],n-x+1),(ll)0);
		else
			ans+=max(min(tavan[i],n-x+1),(ll)0);
		x*=2;
	}
	if(ans>=k) return 1;
	else return 0;
}
int main(){
	cin>>n>>k;tavan[0]=1;
	f(i,1,75) tavan[i]=tavan[i-1]*2;
	cn=n;
	while(cn>0){
		tn++;
		cn/=2;
	}
	ll mid,l=0,r=n+1;
	while(l+1<r){
		mid=(l+r)/2;
		if(check(mid))
			l=mid;
		else r=mid;
	}
	if(check1(l+1)==1)cout<<l+1;
	else cout<<l;
}
#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
ll n,k,l=0,r=1e16,mid;
int check(ll x){
	ll k2=k,sum=x;
	while(x/k2>0)
		sum+=x/k2,k2*=k;
	if(sum<n) return 1;
	return 0;
}
int main(){
	cin>>n>>k;
	while(l+1<r){
		mid=(l+r)/2;
		if(check(mid)) l=mid;
		else r=mid;
	}
	cout<<r;
}
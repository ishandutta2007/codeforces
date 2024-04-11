#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
ll n,m,k,r,l,mid;
bool check(ll x){
	ll j=0;
	f(i,1,n+1){
		j+=min((x-1)/i,m);
		if(j>=k) return false;
	}
	return true;
}
int main(){
	cin>>n>>m>>k;r=1e17;
	while(l+1<r){
		mid=(l+r)/2;
		if(check(mid)) l=mid;
		else r=mid;
	}
	cout<<l;
}
#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
ll m;
ll check(ll x){
	ll j=0,sh;
	for(ll i=2;i*i*i<=x;i++){
		j+=x/(i*i*i);
	}
	if(j>=m)return 0;
	return 1;
}
ll check2(ll x){
	ll j=0,sh;
	for(ll i=2;i*i*i<=x;i++){
		j+=x/(i*i*i);
	}
	return j;
}
int main(){
	cin>>m;
	ll mid,l=0,r=1e18,o;
	while(l+1<r){
		mid=(l+r)/2;
		if(check(mid)){
			l=mid;
		}
		else r=mid;
	}
	if(check2(r)==m)
		cout<<r;
	else cout<<-1;
}
#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
ll n,t,l,r,e=1e6;
pair <ll,ll> p[200009];
bool check(ll x){
	ll p1=0,sum=0;
	f(i,0,n){
		if(p[i].second>=x && p1<x){
			p1++;
			sum+=(p[i].first)/e;
		}
	}
	if(p1==x && sum<=t)return 1;
	return 0;
	
}
int main(){
	cin>>n>>t;
	f(i,0,n){
		cin>>p[i].second>>p[i].first;
		p[i].first=p[i].first*e+i+1;
	}
	sort(p,p+n);
	l=0,r=n+1;
	while(l+1<r){
		ll mid=(l+r)/2;
		if(check(mid)) l=mid;
		else r=mid;
	}
	cout<<l<<endl<<l<<endl;
	ll p2=0;
	f(i,0,n){
		if(p[i].second>=l && p2<l){
			p2++;
			cout<<p[i].first%e<<" ";
		}
	}
}
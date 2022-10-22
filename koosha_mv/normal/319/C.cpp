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
 
const int N=1e5+9;
 
ll n,sz,l,r,mid,s[N],a[N],b[N];
ll dp[N];
vector<pair<ll,ll> > hull;
 
ll sghf(ll x,ll y){
	return (x+y-1)/y;
}
ll tagh(ll b1,ll b2,ll c1,ll c2){
	return sghf(b2-c2,c1-b1);
}
void add_convex_hull(ll x,ll y){
	while(hull.size() && tagh(x,y,hull[hull.size()-1].F,hull[hull.size()-1].S)<s[hull.size()-1])
		hull.pop_back();
	if(hull.size()) s[hull.size()]=tagh(x,y,hull[hull.size()-1].F,hull[hull.size()-1].S);
	hull.pb(mp(x,y));
}
ll Get_convex_hull(ll x){
	l=0,r=hull.size();
	while(l+1<r){
		mid=(l+r)/2;
		if(s[mid]<=x) l=mid;
		else r=mid;
	}
	return 1ll*x*hull[l].F+hull[l].S;
}
 
int main(){
	cin>>n;
	f(i,0,n) cin>>a[i];
	f(i,0,n) cin>>b[i];
	
	add_convex_hull(b[0],0);
	f(i,1,n){
		dp[i]=Get_convex_hull(a[i]);
		add_convex_hull(b[i],dp[i]);	
	}
	cout<<dp[n-1];
}
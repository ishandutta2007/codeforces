#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(ll i=a;i<b;i++)
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
const int N=3e5+9;
ll t,ans,mn;
int n;
pair<ll,ll> p[N];
int main(){
	cin>>t;
	while(t--){
		ans=0;
		gett(n);
		f(i,0,n)
			Get(p[i].F,p[i].S);
		f(i,0,n){
			ans+=p[i].F-min(p[i].F,p[(i-1+n)%n].S);
			p[i].F=min(p[i].F,p[(i-1+n)%n].S);
		}
		mn=1e12;
		f(i,0,n)
			minm(mn,p[i].F);
		cout<<ans+mn<<endl;
	}
}
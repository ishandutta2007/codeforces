#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(int i=a;i>=b;i--)
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

const int N=5e5+99;

int n,t,u1,v1,u2,v2,p1,p2;

void solve(ll x,ll y){
	ll ans=1;
	ans+=y*(y-1)-2*(y-1)+(x-y+1)*(y-1);
	cout<<ans<<endl;
}

int main(){
	cin>>t;
	while(t--){
		cin>>u1>>v1>>u2>>v2;
		p1=max(u2-u1+1,v2-v1+1);
		p2=min(u2-u1+1,v2-v1+1);
		solve(p1,p2);
	}
}
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
const int N=1e6+9;
ll n,t,m,x,y,deg[N],ans;
int main(){
	cin>>n>>m;
	f(i,0,m){
		Gett(x,y)
		deg[x]++;
		deg[y]++;
	}
	f(i,1,n+1)
		ans+=((n-1)*(n-2)/2)-(deg[i]*(n-1-deg[i]));
	ans-=(n*(n-1)*(n-2))/6;
	cout<<ans/2;
}
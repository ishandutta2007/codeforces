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
ll n,t,x,y,x1,x2,yy1,y2,a,b,c,d;
int main(){
	cin>>t;
	while(t--){
		cin>>a>>b>>c>>d;
		cin>>x>>y>>x1>>yy1>>x2>>y2;
		if((x1==x2 && (a || b)) || ((yy1==y2) && (c||d)) || (x-a+b<x1) || (x-a+b>x2) || (y-c+d<yy1) || (y-c+d>y2)) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
}
// owerflow int long long
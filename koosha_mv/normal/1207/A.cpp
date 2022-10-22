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
const int N=3e5+99;
int n,t,x,a[N],b,p,f,h,c,ans;
int main(){
	cin>>t;
	while(t--){
		cin>>b>>p>>f;
		b/=2;
		cin>>h>>c;
		if(h<c) swap(p,f),swap(h,c);
		ans=min(b,p)*h;
		b-=min(b,p);
		ans+=min(b,f)*c;
		cout<<ans<<endl;
	}
}
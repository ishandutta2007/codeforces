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
int n,t,a[N];
pair<int,int> p[N];
int main(){
	cin>>t;
	while(t--){
		int ans=1;
		cin>>n;
		f(i,1,n+1)
			cin>>p[i].F>>p[i].S;
		f(i,1,n){
			if(p[i].F>p[i+1].F || p[i].S>p[i+1].S )
				ans=0;
		}
		f(i,1,n+1){
			if(p[i].S-p[i-1].S>p[i].F-p[i-1].F) ans=0;
		}
		if(ans)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
}
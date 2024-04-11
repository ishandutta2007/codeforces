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

ll a,k,t,ans[N];

ll mndg(ll x){
	ll ans=10;
	while(x){
		minm(ans,x%10);
		x/=10;
	}
	return ans;
}
ll mxdg(ll x){
	ll ans=0;
	while(x){
		maxm(ans,x%10);
		x/=10;
	}
	return ans;
}

int main(){
	cin>>t;
	while(t--){
		cin>>a>>k;
		ans[1]=a;
		if(k==1) cout<<a<<endl;
		else{
			f(i,2,k+1){
				ans[i]=ans[i-1]+mndg(ans[i-1])*mxdg(ans[i-1]);
				if(i==k || mndg(ans[i])==0){
					cout<<ans[i]<<endl;
					break;
				}
			}
		}
	}
}
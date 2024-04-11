#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define Gett(x,y) scanf("%d%d",&x,&y);
#define gett(x) scanf("%d",&x);																																														
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
#define mp make_pair
const int N=3e5+99;
ll n,t,ans[N],mod=998244353;
ll tavan(ll x,ll y){ll p;if(y==0) return 1;if(y%2==0){p=tavan(x,y/2);return (p*p)%mod;}return (tavan(x,y-1)*x)%mod;}
int main(){
	cin>>n;
	f(i,1,n){
		if(i<n-1) ans[i]=((((n-i-1)*810)%mod*tavan(10,n-i-2)))%mod;
		ans[i]=(ans[i]+(((1ll*180*tavan(10,n-i-1)))%mod))%mod;
		cout<<ans[i]<<" ";
	}
	cout<<10;
}
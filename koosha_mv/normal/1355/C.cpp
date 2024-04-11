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

ll n,t,a,b,c,d;
ll ans;


ll calc(ll x){
 return x*(x+1ll)/2ll;
}
int main(){
	cin>>a>>b>>c>>d;
	f(i,a,b+1){
		ans+=calc(min(i,d-c))-calc(min(max(1ll,i+b-c)-1,d-c));
		ans+=max(1ll*0,min(c-(d-i),c-b+1))*(d-c+1);
	}
	cout<<ans;
}
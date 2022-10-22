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
 
const int N=1e6+3,mod=1e9+7;
 
int n,p,t,prv,k,a[N];
ll ans;
 
ll pow(ll x,ll y,ll mod,int s){
	if(y==0) return 1; 
	ll e=pow(x,y/2,mod,s),res=e*e;
	if(res>N && s) k=1,res%=mod;
	if(!s) res%=mod;
	if(y%2) res=res*x;
	if(res>N && s) k=1,res%=mod;
	res%=mod;
	return res;
}
void solve(int x){
	ans=ans*(pow(p,prv,mod,0))%mod;
	f(i,x,n)
		ans=(ans+mod-pow(p,a[i],mod,0))%mod;
}
 
int main(){
	cin>>t;
	f(q,1,t+1){
		Gett(n,p);
		f(i,0,n) gett(a[i]);
		if(p==1){ cout<<(n&1)<<'\n'; continue; }
		
		sort(a,a+n);
		reverse(a,a+n);
		prv=a[0],k=0,ans=0;
		f(i,0,n){
			if(ans!=0) ans=ans*pow(p,prv-a[i],mod,1);
			if(ans>N) k=1,ans%=mod;
			prv=a[i];
			if(ans==0) ans+=1;
			else ans=(ans+mod-1)%mod;
			if(k==1){ ans=(ans+mod)%mod; solve(i+1); break; }
		}
		if(k==0) solve(n);
		printf("%d\n",ans);
	}
}
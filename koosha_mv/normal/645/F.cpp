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
#define Add(x,y) x=(x+y)%mod;
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
 
const int N=1e6+9,M=2e5+2,mod=1e9+7;
 
//math
int fac[N],ifac[N];
ll pow(ll x,ll y,ll mod){if(y==0) return 1; ll p=pow(x,y/2,mod);return ((p*p%mod)*(1+(y%2)*(x-1)))%mod;}
void make_fac(){fac[0]=1; f(i,1,M) fac[i]=1ll*fac[i-1]*i%mod; ifac[M-1]=pow(fac[M-1],mod-2,mod);f_(i,M-2,0) ifac[i]=1ll*ifac[i+1]*(i+1ll)%mod;}
int C(int k,int n){if(k>n) return 0; return 1ll*fac[n]*ifac[n-k]%mod*ifac[k]%mod;}
 
int n,q,k,x,res,a[N],t[N],ans[N];
vector<int> cmp[N];
 
void make_cmp(){
	f(i,1,N)
		for(int j=i;j<N;j+=i)
			cmp[j].pb(i);
}
void do_it(){
	f_(i,N-1,1){
		ans[i]=C(k,t[i]);
		for(int j=i*2;j<N;j+=i)
			Add(ans[i],mod-ans[j]);
		Add(res,1ll*ans[i]*i%mod);
	}
}
void add(int x){
	vector<int> comp=cmp[x];
	f(i,0,comp.size()){
		Add(res,mod-(1ll*ans[comp[i]]*comp[i]%mod));
		f(j,0,cmp[comp[i]].size()-1)
			Add(ans[cmp[comp[i]][j]],ans[comp[i]]);
	}
	f_(i,comp.size()-1,0){
		t[comp[i]]++;
		Add(ans[comp[i]],C(k-1,t[comp[i]]-1));
		Add(res,1ll*ans[comp[i]]*comp[i]%mod);
		f(j,0,cmp[comp[i]].size()-1)
			Add(ans[cmp[comp[i]][j]],mod-ans[comp[i]]);
	}
}
 
int main(){
	make_fac();
	make_cmp();
	cin>>n>>k>>q;
	f(i,0,n){
		gett(x);
		f(j,0,cmp[x].size())
			t[cmp[x][j]]++;
	}
	do_it();
	f(i,0,q){
		gett(x);
		add(x);
		printf("%d ",res);
	}
}
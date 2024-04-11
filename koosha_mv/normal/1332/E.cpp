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

ll n,m,l,r,fr,z,mod=998244353,d=2,p1;
ll pow(ll x,ll y,ll mod){if(y==0) return 1; ll p=pow(x,y/2,mod);return ((p*p%mod)*(1+(y%2)*(x-1)))%mod;}
map<ll,ll> frd;
map<ll,ll> zj;
void solve(ll x){
	if(x==1) return ;
	solve(x/d);
	zj[x]=((frd[x/d]*frd[x/d]%mod)+(zj[x/d]*zj[x/d]%mod))%mod;
	frd[x]=((frd[x/d]*zj[x/d]%mod)*d)%mod;
	if(x%2){
		p1=((frd[x]*zj[1]%mod)+(zj[x]*frd[1]%mod))%mod;
		zj[x]=((zj[x]*zj[1]%mod)+(frd[x]*frd[1]%mod))%mod;
		frd[x]=p1;
	}
}
int main(){
	cin>>n>>m>>l>>r;
	if(n==m && n==1) return cout<<r-l+1ll,0;
	fr=z=(r-l+1ll)/d;
	if(r%d==l%d){
		if(r%2) fr++;
		else z++;
	}
	frd[1]=fr%mod,zj[1]=z%mod;
	solve(n*m);
	if((n*m)%d==1)
		cout<<(frd[n*m]+zj[n*m])%mod<<endl;
	else
		cout<<zj[n*m];
}
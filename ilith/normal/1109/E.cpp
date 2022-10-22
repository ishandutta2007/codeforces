#include<bits/stdc++.h>
#define rgi register int
#define cl(x) memset(x,0,sizeof x)
#define FOR(i,a,b) for(rgi i=a,i##i=b;i<=i##i;++i)
#define ROF(i,a,b) for(rgi i=a,i##i=b;i>=i##i;--i)
typedef long long ll;
using namespace std;
const int N=400010,L=11;
int n,mod,q,P[L],C,v,a[N],h[L],t[L],Ph,o,l,r;
ll qpow(ll a,ll b){
	ll R=1;
	for(a%=mod;b;b>>=1,a=a*a%mod)if(b&1)R=R*a%mod;
	return R;
}
#define mid (l+r>>1)
#define lc k<<1
#define rc lc|1
ll s[N<<2],g[N<<2],mu[N<<2],mg[N<<2],c[N<<2][L];
void chg(int k,ll v,ll z){(g[k]*=z)%=mod,(mg[k]*=z)%=mod,(s[k]*=v)%=mod,(mu[k]*=v)%=mod;}
void pdown(int k){chg(lc,mu[k],mg[k]),chg(rc,mu[k],mg[k]),mu[k]=mg[k]=1;}
void pup(int k){s[k]=(s[lc]+s[rc])%mod,g[k]=(g[lc]+g[rc])%mod;}
void build(int k,int l,int r){
	mu[k]=mg[k]=1;
	if(l==r){
		s[k]=a[l]%mod;
		FOR(i,1,C)while(a[l]%P[i]==0)a[l]/=P[i],++c[k][i];
		return void(g[k]=a[l]%mod);
	}
	build(lc,l,mid),build(rc,mid+1,r),pup(k);
}
ll qry(int x,int y,int k=1,int l=1,int r=n){
	if(l>y||r<x)return 0;
	pdown(k);
	return l<x||r>y?(qry(x,y,lc,l,mid)+qry(x,y,rc,mid+1,r))%mod:s[k];
}
void mul(int x,int y,ll z,int k=1,int l=1,int r=n){
	if(l>y||r<x)return;
	if(l>=x&&r<=y){
		FOR(i,1,C)c[k][i]+=h[i];
		return chg(k,v,z);
	}
	pdown(k),mul(x,y,z,lc,l,mid),mul(x,y,z,rc,mid+1,r),pup(k);
}
void upd(int x,int k=1,int l=1,int r=n){
	if(l>x||r<x)return;
	FOR(i,1,C)t[i]+=c[k][i];
	if(l==r){
		s[k]=g[k]=g[k]*qpow(v,Ph-1)%mod;
		FOR(i,1,C)c[k][i]-=h[i],s[k]=s[k]*qpow(P[i],t[i]-h[i])%mod;
		return;
	}
	pdown(k),upd(x,lc,l,mid),upd(x,rc,mid+1,r),pup(k);
}
int work(int x){
	cl(h);
	FOR(i,1,C)while(x%P[i]==0)++h[i],x/=P[i];
	return x;
}
signed main(){
	scanf("%d%d",&n,&mod),v=Ph=mod;
	FOR(i,2,4e4){
		if(v%i==0)P[++C]=i,Ph=Ph*(i-1ll)/i;
		while(v%i==0)v/=i;
	}
	if(v>1)P[++C]=v,Ph=Ph*(v-1ll)/v;
	FOR(i,1,n)scanf("%d",a+i);
	build(1,1,n);
	for(scanf("%d",&q);q--;){
		scanf("%d%d%d",&o,&l,&r);
		if(o==1)scanf("%d",&v),mul(l,r,work(v));
		if(o==2)cl(t),v=work(r),upd(l);
		if(o==3)printf("%lld\n",qry(l,r));
	}
	return 0;
}
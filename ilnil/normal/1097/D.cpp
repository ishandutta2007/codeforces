#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;i++)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;i--)
#define ll long long
#define c(a,b)(a<=b?jc[b]*ny[a]%mo*ny[b-(a)]%mo:0)
using namespace std;
const int K=100,S=3e5+5,N=2e6+5,M=31622777,mo=1e9+7,Q=(1<<12)+1,ho=1e6+7;
ll n,nn,an,o;
int k,p[N],ps,g[K],bs;
int ds,tt;
ll f[ho],h[ho],d[S],b[K],gs[S],u[51][10005][51],iv[60];
#include<bitset>
bitset<M>bz;
ll ksm(ll x,int y){
	ll t=1;
	for(;y;y>>=1,x=x*x%mo)if(y&1)t=t*x%mo;
	return t;
}
int ha(ll x){
	int y=x%ho;
	for(;h[y]&&h[y]!=x;)++y==ho?y=0:0;
	return y;
}
void go(int x,ll y,int gg,ll ans){
	if(x>bs){
		d[++ds]=y;gs[ds]=gg;
		h[ha(y)]=y;
		f[ha(y)]=ans;
		return;
	}
	fo(i,0,g[x]){
		go(x+1,y,gg*(i+1),ans*u[g[x]][k][i]%mo);
		if(i!=g[x])y*=b[x];
	}
}
int main(){
	scanf("%lld%d",&n,&k);nn=n;
	fo(i,2,M-1){
		if(!bz[i])p[++ps]=i;
		for(int j=1,u;(u=i*p[j])<M;j++){
			bz[u]=1;
			if(i%p[j]==0)break;
		}
	}
	fo(i,1,ps){
		if((ll)p[i]*p[i]>n)break;
		if(n%p[i]==0){
			for(b[++bs]=p[i];g[bs]++,n/=p[i],n%p[i]==0;);
		}
	}
	if(n>1)b[++bs]=n,g[bs]=1;
	iv[1]=1;
	fo(i,2,50)iv[i]=mo-iv[mo%i]*(mo/i)%mo;
	fo(i,1,50){
		u[i][0][0]=1;
		fo(j,1,k){
			fo(k,0,i)u[i][j][k]=((k?u[i][j][k-1]:0)+u[i][j-1][k]*iv[i+1-k])%mo;
		}
	}
	go(1,1,1,1);
	fo(i,1,ds)
		an=(an+d[i]%mo*f[ha(nn/d[i])])%mo;
	printf("%lld",an/**ksm(ksm(gs[ds],k),mo-2)%mo*/);
}
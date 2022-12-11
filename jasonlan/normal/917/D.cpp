#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
typedef long long ll;
const int maxn=120,mod=1e9+7;
int n;
ll ans;
ll qmod(ll x){
	return x>=mod?x-mod:x;
}
ll qpow(ll x,ll k){
	ll res=1;
	while(k){
		if(k&1)res=res*x%mod;
		x=x*x%mod;
		k>>=1;
	}
	return res;
}
ll getinv(ll x){
	return qpow(x,mod-2);
}
bool e[maxn][maxn];
ll a[maxn][maxn],b[maxn][maxn];
ll det(){
	ll res=1;
	bool tag=1;
	for(register int j=2;j<=n;++j){
		for(register int i=j;i<=n;++i){
			if(!a[i][j])continue;
			tag^=i!=j;
			swap(a[i],a[j]);
			break;
		}
		if(!a[j][j])return 0;
		res=res*a[j][j]%mod;
		ll inv=getinv(a[j][j]);
		for(register int i=j+1;i<=n;++i){
			ll ginv=a[i][j]*inv%mod;
			for(register int k=j;k<=n;++k)
				a[i][k]=qmod(a[i][k]-ginv*a[j][k]%mod+mod);
		}
	}
	return tag?res:qmod(mod-res);
}
void gauss(){
	for(register int j=0;j<n;++j){
		for(register int i=j;i<n;++i){
			if(!b[i][j])continue;
			swap(b[i],b[j]);
			break;
		}
		if(!b[j][j])return;
		ll inv=getinv(b[j][j]);
		for(register int k=j;k<=n;++k)
			b[j][k]=b[j][k]*inv%mod;
		for(register int i=0;i<n;++i){
			inv=b[i][j]%mod;
			if(i==j||!inv)continue;
			for(register int k=j;k<=n;++k)
				b[i][k]=qmod(b[i][k]-inv*b[j][k]%mod+mod);
		}
	}
}
int main(){
	scanf("%d",&n);
	for(register int i=1,x,y;i<n;++i){
		scanf("%d%d",&x,&y);
		e[x][y]=e[y][x]=true;
	}
	for(register int x=0;x<n;++x){
		for(register int i=1;i<=n;++i){
			for(register int j=1;j<=n;++j)
				a[i][j]=0;
			for(register int j=1;j<=n;++j){
				if(i==j)continue;
				if(!e[i][j]){
					a[i][j]=qmod(a[i][j]-1+mod);
					a[i][i]=qmod(a[i][i]+1);
				}
				else{
					a[i][j]=qmod(a[i][j]-x+mod);
					a[i][i]=qmod(a[i][i]+x);
				}
			}
		}
		b[x][n]=det();
		for(register int i=0,j=1;i<n;++i){
			b[x][i]=j;
			j=1ll*j*x%mod;
		}
	}
	gauss();
	for(register int i=0;i<n;++i)
		printf("%lld ",b[i][n]);
	return 0;
}
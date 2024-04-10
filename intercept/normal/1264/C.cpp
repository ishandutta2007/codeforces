#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int M=2e5+9;
int n,q,ans=0;
int p[M],s[M],d[M],BT[M];
bool vis[M];
int kpow(int x,int y,int rex=1){
	for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)rex=1ll*x*rex%mod;
	return rex;
}
void add(int i,int v){for(;i<=n;i+=i&-i)BT[i]=(BT[i]+v)%mod;}
int sum(int i,int rex=0){for(;i;i-=i&-i)rex=(rex+BT[i])%mod;return rex;}
int kth(int k,int rex=0){
	for(int i=1<<19;i;i>>=1)
		if(rex+i<=n&&BT[rex+i]<k)k-=BT[rex+=i];
	return rex+1;
}
int inv(int x){return kpow(x,mod-2);}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i)scanf("%d",&p[i]);
	s[n+1]=1;
	for(int i=n;i>=1;--i){
		s[i]=1ll*s[i+1]*p[i]%mod*inv(100)%mod;
		d[i]=(inv(s[i])+d[i+1])%mod;
	}
	n++;
	add(1,1);
	add(n,1);
	ans=d[1];
	for(int i=1,u,l,r,o;i<=q;++i){
		scanf("%d",&u);
		o=sum(u);
		l=kth(vis[u]?o-1:o);
		r=kth(o+1);
		ans=(ans+(1ll*(d[l]-d[u])*(s[u]-s[r])*(vis[u]?-1:1))%mod)%mod;
		if(vis[u])add(u,-1);
		else add(u,1);
		vis[u]^=1;
		printf("%d\n",(ans+mod)%mod);
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int M=1e6+9;
int n,m;
int a[M],c[M],b,T;
long long p[M],s[M],v[M],l[M];
void work(){
	int g=0;
	long long ans=0;
	c[0]=0;l[0]=1e18;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),c[i]=0,l[i]=1e18;
	for(int i=1;i<=m;++i)scanf("%d",&b),g=__gcd(g,b);
	for(int i=1;i<=n;++i){
		if(a[i]<0)c[i%g]^=1,a[i]=-a[i];
	}
	for(int i=1;i<=n;++i)p[i]=p[i-1]+a[i];
	long long s1=0,s2=0;
	for(int i=1;i<=n;++i){
		l[i%g]=min(l[i%g],1ll*a[i]);
	}
	for(int i=0;i<g;++i)c[i]?s1+=l[i]:s2+=l[i];
	ans=max(ans,p[n]-2ll*min(s1,s2));
	printf("%lld\n",ans);
}
int main(){
	for(scanf("%d",&T);T;--T)work();
	return 0;
}
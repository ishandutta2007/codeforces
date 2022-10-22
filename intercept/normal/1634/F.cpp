#include<bits/stdc++.h>
using namespace std;
const int M=3e5+9;
const int sed=131;
int n,q,mod;
int a[M],b[M],f[M];
long long x1,x2,p[M];
int main(){
	scanf("%d%d%d",&n,&q,&mod);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)scanf("%d",&b[i]);
	for(int i=n;i>=2;--i){
		a[i]=((1ll*a[i]-a[i-1]-a[i-2])%mod+mod)%mod;
		b[i]=((1ll*b[i]-b[i-1]-b[i-2])%mod+mod)%mod;
	}
	f[1]=p[0]=1;
	for(int i=2;i<=n;++i)f[i]=(f[i-1]+f[i-2])%mod;
	for(int i=1;i<=n;++i)p[i]=p[i-1]*sed,x1+=p[i]*a[i],x2+=p[i]*b[i];
	for(int i=1;i<=q;++i){
		char c[5];
		int l,r;
		scanf("%s%d%d",c,&l,&r);
		if(c[0]=='A'){
			x1-=a[l]*p[l]+a[r+1]*p[r+1]+a[r+2]*p[r+2];
			a[l]=(a[l]+1)%mod;
			a[r+1]=(a[r+1]+mod-f[r-l+2])%mod;
			a[r+2]=(a[r+2]+mod-f[r-l+1])%mod;
			x1+=a[l]*p[l]+a[r+1]*p[r+1]+a[r+2]*p[r+2];
		}
		else{
			x2-=b[l]*p[l]+b[r+1]*p[r+1]+b[r+2]*p[r+2];
			b[l]=(b[l]+1)%mod;
			b[r+1]=(b[r+1]+mod-f[r-l+2])%mod;
			b[r+2]=(b[r+2]+mod-f[r-l+1])%mod;
			x2+=b[l]*p[l]+b[r+1]*p[r+1]+b[r+2]*p[r+2];
		}
		puts(x1==x2?"YES":"NO");
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0,f=1;char ch=getchar();
	while ((ch!='-')&&(!isdigit(ch))) ch=getchar();
	if (ch=='-') f=-1,ch=getchar();
	while (isdigit(ch)) x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return x*f;
}
#define MOD 1000000007
long long cnt,a[1001010],b[1001010],d[1001010],fac[1001010],ifac[1001010];
long long dep[1001010],siz[1001010];
long long rt,ans,n,i,m,x,y;
void add(int x,int y){
	cnt++;a[cnt]=y;b[cnt]=d[x];d[x]=cnt;
}
long long pow(long long x,long long y,long long p){
	long long ans=1;
	for (;y;y>>=1,x=x*x % p)
	   if (y&1) ans=ans*x % p;return ans;}
long long C(long long n,long long m){
	if ((n<0)||(m<0)||(n<m)) return 0;
	return fac[n]*ifac[m] % MOD*ifac[n-m] % MOD;
}
void sc(int x,int fa){
	dep[x]=dep[fa]+1;siz[x]=1;
	for (int i=d[x];i;i=b[i])
	    if (a[i]!=fa)
	        {
	        	sc(a[i],x);
	        	siz[x]+=siz[a[i]];
			}
	long long vtot;
	long long tot=C(siz[x],m);
	for (int i=d[x];i;i=b[i]) 
	    if (a[i]!=fa) tot=(tot-C(siz[a[i]],m)+MOD) % MOD;
    ans=(ans+tot % MOD*siz[x] % MOD*(n-siz[x])) % MOD;
    for (int i=d[x];i;i=b[i])
        if (a[i]!=fa){
        	vtot=tot-C(siz[x],m)+C(siz[x]-siz[a[i]]+n-siz[x],m);
        	vtot=vtot+C(siz[a[i]],m);
			vtot=vtot-C(n-siz[x],m);
			vtot=(vtot % MOD+MOD) % MOD;
			ans=(ans+vtot % MOD*(siz[x]-siz[a[i]]+n-siz[x]) % MOD*siz[a[i]]) % MOD;
			}
	tot=C(n,m);
	for (int i=d[x];i;i=b[i])
	     if (a[i]!=fa) tot=(tot-C(siz[a[i]],m)+MOD) % MOD;
	tot=(tot-C(n-siz[x],m)+MOD) % MOD;
	ans=(ans+tot*n) % MOD;
}
int main() {
	n=read();m=read();
	for (i=1;i<n;i++){
		x=read();y=read();
		add(x,y);add(y,x);
	}
	fac[0]=1;
	for (i=1;i<=n;i++) fac[i]=fac[i-1]*i % MOD;
	ifac[n]=pow(fac[n],MOD-2,MOD);
	for (i=n-1;i>=0;i--) ifac[i]=ifac[i+1]*(i+1) % MOD;
	sc(1,0);
	printf("%lld\n",ans);
	return 0;
}
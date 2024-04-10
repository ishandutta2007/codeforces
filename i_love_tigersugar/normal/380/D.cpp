//This solution is based on rng_58's solution
#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
const int mod=(int)1e9+7;
int a[MAX];
int s[MAX];
int frac[MAX],inv[MAX],finv[MAX];
int n;
int pw(int a,int b) {
	int ret=1;
	int mul=a;
	while (b>0) {
		if (b%2>0) ret=(1LL*ret*mul)%mod;
		mul=(1LL*mul*mul)%mod;
		b=b>>1;
	}
	return (ret);
}
void init(void) {
	scanf("%d",&n);
	FOR(i,1,n) {
		scanf("%d",&a[i]);
		s[i]=s[i-1]+(a[i]>0);
	}
	frac[0]=1LL;
	finv[0]=1LL;
	FOR(i,1,n) {
		frac[i]=(1LL*frac[i-1]*i)%mod;
		inv[i]=pw(i,mod-2);
		finv[i]=(1LL*finv[i-1]*inv[i])%mod;
	}
}
int comb(int n,int k) {
//	printf("COMB %d %d\n",n,k);
	if (k>n) return (0);
	return (1LL*frac[n]*finv[k]%mod*finv[n-k]%mod);
}
int count(int l,int r) {
//	printf("COUNT %d %d\n",l,r);
	if (s[l-1]==s[r]) return (pw(2,r-l));
	int x,y;
	for (x=l;x<=r;x=x+1) if (a[x]>0) break;
	for (y=r;y>=l;y=y-1) if (a[y]>0) break;
	if (x==y && a[x]==1) return (comb(r-l,x-l));
	int ans=0;
	if (a[x]>=a[y]) {
		int tl=x+1;
		int tr=x+a[x]-1;
		if (tr<=r && tr>=y) ans+=(1LL*count(tl,tr)*comb(r-tr+tl-l-1,r-tr))%mod;
	}
	if (a[y]>=a[x]) {
		int tr=y-1;
		int tl=y-a[y]+1;
		if (tl>=l && tl<=x) ans+=(1LL*count(tl,tr)*comb(r-tr+tl-l-1,tl-l))%mod;
	}
//	printf("RET %d\n",ans);
	return (ans%mod);
}
void process(void) {
	printf("%d",count(1,n));
}
int main(void) {
	init();
	process();
	return 0;
}
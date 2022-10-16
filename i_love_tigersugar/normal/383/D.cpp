#include<bits/stdc++.h>
#define MAXN   1010
#define MAXV   10010
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
const int mod=(int)1e9+7;
int f[MAXN][2*MAXV];
int a[MAXN];
int n,s;
void init(void) {
	scanf("%d",&n);
	FOR(i,1,n) {
		scanf("%d",&a[i]);
		s+=a[i];
	}	
}
void optimize(void) {
	int res=0;
	FOR(i,1,n) {
		f[i-1][MAXV]=(f[i-1][MAXV]+1)%mod;
		FOR(j,-s,s) f[i][j+MAXV]=(f[i-1][j-a[i]+MAXV]+f[i-1][j+a[i]+MAXV])%mod;
		res=(res+f[i][MAXV])%mod;
	}
	printf("%d",res);
}
int main(void) {
	init();
	optimize();
	return 0;
}
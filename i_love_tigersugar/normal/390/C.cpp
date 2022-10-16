#include<bits/stdc++.h>
#define MAXN   100100
#define MAXK   13
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
char a[MAXN];
int c[MAXN][MAXK],s[MAXN][MAXK];
int n,k,q;
void init(void) {
	scanf("%d",&n);
	scanf("%d",&k);
	scanf("%d",&q);
	scanf("%s",a+1);
	FOR(i,1,n) REP(j,k) {
		c[i][j]=c[i-1][j]+(i%k==j);
		s[i][j]=s[i-1][j]+(i%k==j && a[i]=='1');		
	}
}
void process(void) {
	REP(i,q) {
		int l,r;
		scanf("%d",&l);
		scanf("%d",&r);
		int p=(l-1)%k;
		int res=(c[r][p]-c[l-1][p])-(s[r][p]-s[l-1][p]);
		REP(j,k) if (j!=p) res+=s[r][j]-s[l-1][j];
		printf("%d\n",res);
	}
}
int main(void) {
	init();
	process();
	return 0;
}
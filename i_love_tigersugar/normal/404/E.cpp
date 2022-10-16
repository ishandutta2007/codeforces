//This solution is based on author's solution
#include<bits/stdc++.h>
#define MAX   1000100
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
char s[MAX];
int lev[MAX];
int n;
void init(void) {
	scanf("%s",s+1);
	n=strlen(s+1);
	if (s[n]=='L') FOR(i,1,n) s[i]^='L'^'R';	
}
bool ok(int x) {
	FOR(i,1,n) {
		lev[i]=lev[i-1]+(s[i]=='L'?-1:1);
		if (lev[i]<=x) lev[i]++;
	}
	FOR(i,1,n-1) if (lev[i]>=lev[n]) return (false);
	return (lev[n]>0);
}
void process(void) {
	int l=-n-7;
	int r=0;
	int m;
	while (true) {
		if (l==r) {
			m=l;
			break;
		}
		if (r-l==1) {
			if (ok(l)) m=l;	else m=r;
			break;
		}
		m=(l+r)/2;
		if (ok(m)) r=m; else l=m+1;
	}
	if (m<-n) printf("1"); else printf("%d",-m);
}
int main(void) {
	init();
	process();
	return 0;
}
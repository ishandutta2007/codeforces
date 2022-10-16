#include<bits/stdc++.h>
#define MAX   1000100
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define add(a,b) a=(a+b)%mod
const int mod=(int)1e9+7;
const bool ok[][4]={{1,1,0,0},{0,0,0,1},{0,0,0,0},{0,1,1,1}};
char s[MAX];
int f[MAX][7];
int n;
void init(void) {
	scanf("%s",s+1);
	n=strlen(s+1);
	FOR(i,1,n) {
		if (s[i]=='?') continue;
		if (s[i]=='*') s[i]=3; else s[i]-=48;
	}
}
void optimize(void) {
	REP(i,4) if (i!=2 && (s[1]=='?' || s[1]==i)) f[1][i]++;
	REP(i,n) REP(j,4) if (f[i][j]>0) {		
		REP(k,4) if (ok[j][k])
			if (s[i+1]=='?' || s[i+1]==k)
				add(f[i+1][k-(j==3 && k!=3)],f[i][j]);							
	}	
	printf("%d",(f[n][0]+f[n][3])%mod);
}
int main(void) {
	init();
	optimize();
	return 0;
}
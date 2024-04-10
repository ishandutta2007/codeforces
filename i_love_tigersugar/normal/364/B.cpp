#include<cstdio>
#define MAXN   53
#define MAXV   10010
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
bool f[MAXN][MAXN*MAXV];
int c[MAXN];
int s[MAXN];
int next[MAXN*MAXV];
int n,d;
void init(void) {
	scanf("%d",&n);
	scanf("%d",&d);
	FOR(i,1,n) {
		scanf("%d",&c[i]);
		s[i]=s[i-1]+c[i];
	}	
}
void optimize(void) {
	f[0][0]=true;
	FOR(i,1,n) REP(j,s[i]+1) {
		f[i][j]=f[i-1][j];
		if (c[i]<=j) f[i][j]=f[i][j]||f[i-1][j-c[i]];
	}
}
void findnext(void) {
	REP(i,s[n]+1) next[i]=-1;
	FOR(i,1,d) if (i<=s[n] && f[n][i]) next[0]=i;
	FOR(i,1,s[n]) {
		if (i+d<=s[n] && f[n][i+d]) next[i]=i+d;
		else if (next[i-1]>i) next[i]=next[i-1];
	}
	int cur=0;
	int cnt=0;
	while (next[cur]>=0) {
		cur=next[cur];
		cnt++;
	}
	printf("%d %d",cur,cnt);
}
int main(void) {
	init();
	optimize();
	findnext();
	return 0;
}
#include<cstdio>
#include<cstring>
#define MAXN   4004
#define MAXK   808
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define FORD(i,b,a) for (int i=(b);i>=(a);i=i-1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
const int INF=(int)1e9+7;
int a[MAXN][MAXN];
int s[MAXN][MAXN];
int f[MAXK][MAXN];
char inp[MAXN<<2];
int n,q;
void init(void) {
	scanf("%d",&n);
	scanf("%d",&q);
	gets(inp);
	FOR(i,1,n) {
		gets(inp);
		FOR(j,1,n) {
			a[i][j]=inp[2*j-2]-48;
			s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];			
		}		
	}
}
int cost(const int &l,const int &r) {
	return ((s[r][r]-s[l-1][r]-s[r][l-1]+s[l-1][l-1])>>1);
}	
void dp(int k,int l,int r,int ul,int ur) {
	if (l>r) return;
	int m=(l+r)/2;
	int im;
	f[k][m]=INF;
	FOR(i,ul,ur) if (f[k][m]>f[k-1][i]+cost(i+1,m)) {
		f[k][m]=f[k-1][i]+cost(i+1,m);
		im=i;
	}
	dp(k,l,m-1,ul,im);
	dp(k,m+1,r,im,ur);
}
void process(void) {
	FOR(i,1,n) f[1][i]=cost(1,i);
	FOR(i,2,q) dp(i,1,n,1,n);
	printf("%d",f[q][n]);
}
int main(void) {
	init();
	process();
	return 0;
}
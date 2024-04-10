#include<bits/stdc++.h>
#define MAX   20
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define FORD(i,b,a) for (int i=(b);i>=(a);i=i-1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define fi   first
#define se   second
using namespace std;
const int INF=(int)1e9+7;
typedef pair<char,int> ci;
int a[111];
int f[MAX+3][(1<<MAX)+7];
int n,m;
ci e[MAX+3];
void minimize(int &x,const int &y) {
	if (x>y) x=y;
}
void maximize(int &x,const int &y) {
	if (x<y) x=y;
}
int bit(int x,int i) {
	return ((x|(1<<i))==x);
}
void init(void) {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	scanf("%d",&m);
	FOR(i,1,m) {
		scanf(" %c",&e[i].fi);
		scanf("%d",&e[i].se);
	}
	sort(a,a+n,greater<int>());
}
void optimize(void) {
	FORD(i,m,1) REP(j,1<<m) {
		int p=e[i].se;
		if (p==1) f[i][j]=-INF; else f[i][j]=INF;
		if (e[i].fi=='b') {
			if (p==1) maximize(f[i][j],f[i+1][j]);
			else minimize(f[i][j],f[i+1][j]);
			REP(k,m) if (!bit(j,k)) {
				if (p==1) maximize(f[i][j],f[i+1][j|(1<<k)]);
				else minimize(f[i][j],f[i+1][j|(1<<k)]);
			}			
		}
		else {
			REP(k,m) if (!bit(j,k)) {
				if (p==1) f[i][j]=f[i+1][j|(1<<k)]+a[k];
				else f[i][j]=f[i+1][j|(1<<k)]-a[k];
				break;
			}
		}
	}
	printf("%d",f[1][0]);
}
int main(void) {
	init();
	optimize();
	return 0;
}
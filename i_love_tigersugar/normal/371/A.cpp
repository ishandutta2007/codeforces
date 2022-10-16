#include<cstdio>
#include<queue>
#define MAX   111
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
int n,k;
int c[MAX][3];
int main(void) {
	scanf("%d",&n);
	scanf("%d",&k);
	REP(i,n) {
		int t;
		scanf("%d",&t);
		c[i%k][t]++;
	}
	int res=0;
	REP(i,k) res+=min(c[i][1],c[i][2]);
	printf("%d",res);
	return 0;
}
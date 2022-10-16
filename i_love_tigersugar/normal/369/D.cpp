#include<cstdio>
#include<cstring>
#include<queue>
#define	MAX   3030
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define FORD(i,b,a) for (int i=(b);i>=(a);i=i-1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define fi   first
#define se   second
using namespace std;
typedef pair<int,int> ii;
int p[MAX];
int m[MAX];
int d[MAX][MAX];
int n,k;
void init(void) {
	scanf("%d",&n);
	scanf("%d",&k);
	FOR(i,1,n) scanf("%d",&p[i]);
	FORD(i,n,1) {
		if (p[i]>m[i+1]) m[i]=p[i];
		else m[i]=m[i+1];
	}
}
void BFS(void) {
	queue<ii> q;
	while (!q.empty()) q.pop();
	ii u;
	memset(d,0x3f,sizeof d);
	d[1][2]=0;
	q.push(ii(1,2));
	while (!q.empty()) {
		u=q.front();q.pop();
		if (u.se>n) continue;
		if (d[u.fi][u.se]>=k) continue;
		if (m[u.se]>0 && p[u.fi]<100 && d[u.se][u.se+1]>k) {
			d[u.se][u.se+1]=d[u.fi][u.se]+1;
			q.push(ii(u.se,u.se+1));
		}
		if (p[u.fi]>0 && m[u.se]<100 && d[u.fi][u.se+1]>k) {
			d[u.fi][u.se+1]=d[u.fi][u.se]+1;
			q.push(ii(u.fi,u.se+1));
		}
		if (m[u.se]>0 && p[u.fi]>0 && d[u.se+1][u.se+2]>k) {
			d[u.se+1][u.se+2]=d[u.fi][u.se]+1;
			q.push(ii(u.se+1,u.se+2));
		}
	}
}
void count(void) {
	int res=0;
	FOR(i,1,n) FOR(j,i+1,n+1)
		if (d[i][j]<=k) res++;
	if (d[n+1][n+2]<=k) res++;
	printf("%d",res);
}
int main(void) {
	init();
	BFS();
	count();
	return 0;
}
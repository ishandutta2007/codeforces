#include<algorithm>
#include<cstdio>
#include<cstring>
#define MAX   1000100
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
char s[MAX];
int no[MAX],nc[MAX],lev[MAX],lg2[MAX];
int rmq[MAX][22];
int n,q;
int min(int x,int y) {
	if (x<y) return (x); else return (y);
}
void init(void) {
	scanf("%s",s+1);
	n=strlen(s+1);
	FOR(i,1,n) {
		no[i]=no[i-1]+(s[i]=='(');
		nc[i]=nc[i-1]+(s[i]==')');
		lev[i]=no[i]-nc[i];
	}
}
void setup_rmq(void) {
	FOR(i,1,n) rmq[i][0]=lev[i];
	FOR(j,1,21) FOR(i,1,n+1-(1<<j)) rmq[i][j]=min(rmq[i][j-1],rmq[i+(1<<(j-1))][j-1]);
	FOR(i,1,n) {
		while ((1<<lg2[i])<=i) lg2[i]++;
		lg2[i]--;
	}	
}
int getmin(int l,int r) {
	int k=lg2[r-l+1];
	return (min(rmq[l][k],rmq[r-(1<<k)+1][k]));
}
bool ok(int l,int r,int x) {
	if (nc[r]-nc[l-1]<x) return (false);
	if (x==0) return (true);
	int t=lower_bound(nc,nc+n+1,nc[r]-x+1)-nc;
	return (getmin(t,r)-no[l-1]+nc[t-1]>=0);
}
int answer(int u,int v) {
	int l=0;
	int r=nc[v]-nc[u-1];
	while (true) {
		if (l==r) return (r);
		if (r-l==1) {
			if (ok(u,v,r)) return (r);
 			else return (l);
		}
		int m=(l+r)/2;
		if (ok(u,v,m)) l=m;
		else r=m-1;
	}
}
void process(void) {
	scanf("%d",&q);
	REP(i,q) {
		int l,r;
		scanf("%d",&l);
		scanf("%d",&r);
		printf("%d\n",2*answer(l,r));
	}
}
int main(void) {
#ifndef ONLINE_JUDGE
	freopen("tmp.txt","r",stdin);
#endif
	init();
	setup_rmq();
	process();
	return 0;
}
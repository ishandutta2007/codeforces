//This solution is based on kien_coi_1997's solution
#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define FORD(i,b,a) for (int i=(b);i>=(a);i=i-1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define fi   first
#define se   second
using namespace std;
typedef long long ll;
typedef pair<int,ll> ii;
ii operator - (const ii &a,const ii &b) {
	return (ii(a.fi-b.fi,a.se-b.se));
}
ii a[MAX];
int next[MAX][18],h[MAX];
int n,q;
bool cansee(const ii &a,const ii &b,const ii &c) {
	ii ab=b-a;
	ii ac=c-a;
	return (ac.se*ab.fi>ac.fi*ab.se);
}
void init(void) {
	cin >> n;
	FOR(i,1,n) cin >> a[i].fi >> a[i].se;
	next[n][0]=n;
	FORD(i,n-1,1) {
		next[i][0]=i+1;
		while (cansee(a[i],a[next[i][0]],a[next[next[i][0]][0]]))
			next[i][0]=next[next[i][0]][0];
		h[i]=h[next[i][0]]+1;
	}
	FOR(j,1,17) FOR(i,1,n) next[i][j]=next[next[i][j-1]][j-1];
}
int lca(int u,int v) {
	if (h[u]<h[v]) return (lca(v,u));
	FORD(i,17,0) if (h[next[u][i]]>=h[v]) u=next[u][i];
	if (u==v) return (u);
	FORD(i,17,0) if (next[u][i]!=next[v][i]) {
		u=next[u][i];
		v=next[v][i];
	}
	return (next[u][0]);
}
void process(void) {
	cin >> q;
	REP(zz,q) {
		int u,v;
		cin >> u >> v;
		if (zz>0) printf(" ");
		printf("%d",lca(u,v));
	}
}
int main(void) {
	init();
	process();
	return 0;
}
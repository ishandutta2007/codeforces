#include<cstdio>
#include<vector>
#define MAX   1000100
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define FORD(i,b,a) for (int i=(b);i>=(a);i=i-1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
int p[MAX][22];
int h[MAX];
int n;
void init(void) {
	n=4;
	h[0]=-1;
	FOR(i,2,4) {
		h[i]=1;
		p[i][0]=1;
	}
	FOR(j,1,21) FOR(i,1,n) p[i][j]=p[p[i][j-1]][j-1];
}
void addnode(int u) {
	REP(zz,2) {
		n++;
		p[n][0]=u;
		h[n]=h[u]+1;
		FOR(j,1,21) p[n][j]=p[p[n][j-1]][j-1];
	}	
}
int LCA(int u,int v) {
	if (h[u]<h[v]) return (LCA(v,u));
	FORD(i,21,0) if (h[p[u][i]]>=h[v]) u=p[u][i];
	if (u==v) return (v);
	FORD(i,21,0) if (p[u][i]!=p[v][i]) {
		u=p[u][i];
		v=p[v][i];
	}
	return (p[u][0]);
}
int dis(int u,int v) {
	int w=LCA(u,v);
	return (h[u]+h[v]-2*h[w]);
}
void process(void) {
	int q;
	scanf("%d",&q);
	int pu=2;
	int pv=4;
	REP(zz,q) {
		int u;
		scanf("%d",&u);
		addnode(u);
		vector<int> tmp;
		tmp.clear();
		tmp.push_back(pu);
		tmp.push_back(pv);
		tmp.push_back(n-1);
		tmp.push_back(n);		
		int res=-1;
		REP(i,4) FOR(j,i+1,3) {
			int t=dis(tmp[i],tmp[j]);
			if (t>res) {
				res=t;
				pu=tmp[i];
				pv=tmp[j];
			}
		}
		printf("%d\n",res);
	}
}
int main(void) {
	init();
	process();
	return 0;
}
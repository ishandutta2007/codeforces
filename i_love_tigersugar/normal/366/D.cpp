#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<queue>
#define MAX   3030
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
struct edge {
	int u,v,l,r;
	edge(){}
	edge(int _u,int _v,int _l,int _r) {
		u=_u;v=_v;l=_l;r=_r;
	}	
};
edge e[MAX];
vector<edge> g[MAX];
bool vst[MAX];
int n,m;
void loadgraph(void) {
	scanf("%d",&n);
	scanf("%d",&m);
	int u,v,l,r;
	REP(i,m) {
		scanf("%d",&u);
		scanf("%d",&v);
		scanf("%d",&l);
		scanf("%d",&r);
		e[i]=edge(u,v,l,r);
		g[u].push_back(edge(u,v,l,r));
		g[v].push_back(edge(v,u,l,r));
	}
}
void checkans(void) {
	queue<int> q;
	while (!q.empty()) q.pop();
	FOR(i,1,n) vst[i]=false;
	vst[1]=true;
	q.push(1);
	int u;
	while (!q.empty()) {
		u=q.front();q.pop();
		if (u==n) return;
		FORE(it,g[u]) if (!vst[it->v]) {
			vst[it->v]=true;
			q.push(it->v);			
		}
	}
	if (!vst[n]) {
		printf("Nice work, Dima!");
		exit(0);
	}
}
bool BFS(const int &ml,const int &mr) {
	queue<int> q;
	while (!q.empty()) q.pop();
	FOR(i,1,n) vst[i]=false;
	vst[1]=true;
	q.push(1);
	int u;
	while (!q.empty()) {
		u=q.front();q.pop();
		if (u==n) return (true);
		FORE(it,g[u])
			if (!vst[it->v] && it->l<=ml && it->r>=mr) {
				vst[it->v]=true;
				q.push(it->v);				
			}		
	}
	return (vst[n]);
}
bool ok(const int &d) {
	if (d==0) return (true);
	REP(i,m) if (BFS(e[i].l,e[i].l+d-1)) return (true);
	REP(i,m) if (BFS(e[i].r-d+1,e[i].r)) return (true);
	return (false);
}
void print(const int &x) {
	if (x==0) printf("Nice work, Dima!");
	else printf("%d",x);
}
void process(void) {
	int l=0;
	int r=(int)1e6+7;
	int m;
	while (true) {
		if (l==r) {
			print(l);
			return;
		}
		if (r-l==1) {
			if (ok(r)) print(r);
			else print(l);
			return;
		}
		m=(l+r)/2;
		if (ok(m)) l=m;
		else r=m-1;
	}
}
int main(void) {
	loadgraph();
	process();
	return 0;	
}
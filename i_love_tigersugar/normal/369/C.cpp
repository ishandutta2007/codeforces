#include<cstdio>
#include<vector>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define fi   first
#define se   second
using namespace std;
typedef pair<int,int> ii;
vector<ii> g[MAX];
int p[MAX];
bool con[MAX];
bool chs[MAX];
int n;
void loadtree(void) {
	scanf("%d",&n);
	int u,v,t;
	REP(i,n-1) {
		scanf("%d",&u);
		scanf("%d",&v);
		scanf("%d",&t);
		g[u].push_back(ii(v,t));
		g[v].push_back(ii(u,t));
	}
	p[1]=-1;
}
void visit(const int &u) {	
	int v;
	con[u]=false;
	FORE(it,g[u]) if (it->fi!=p[u]) {
		v=it->fi;		
		p[v]=u;		
		visit(v);
		con[u]=con[u]||con[v]||(it->se==2);
		chs[v]=(!con[v]) && (it->se==2);
	}
}
void process(void) {
	visit(1);
	int cnt=0;
	FOR(i,1,n) if (chs[i]) cnt++;
	printf("%d\n",cnt);
	bool prev=false;
	FOR(i,1,n) if (chs[i]) {
		if (prev) printf(" ");
		else prev=true;
		printf("%d",i);
	}
}
int main(void) {
	loadtree();
	process();
	return 0;
}
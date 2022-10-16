#include<cstdio>
#include<vector>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define fi   first
#define se   second
using namespace std;
typedef pair<int,int> ii;
struct BIT {
	vector<int> v;
	int n;
	BIT() {
		v=vector<int>();
		n=0;
	}
	BIT(int _n) {
		n=_n;
		v=vector<int>(n+7,0);
	}
	void update(int x,int t) {
		while (1<=x && x<=n) {
			v[x]+=t;
			x+=x&(-x);
		}
	}
	int get(int x) const {
		int ret=0;
		while (1<=x && x<=n) {
			ret+=v[x];
			x=x&(x-1);
		}
		return (ret);
	}
	int countgreater(int x) const {
		return (get(n)-get(x-1));
	}
};
vector<int> g[MAX];
vector<ii> qat[MAX];
BIT bit;
int c[MAX],p[MAX],sz[MAX],cnt[MAX],ans[MAX];
int n,q;
void loadtree(void) {
	scanf("%d",&n);
	scanf("%d",&q);
	FOR(i,1,n) scanf("%d",&c[i]);
	REP(i,n-1) {
		int u,v;
		scanf("%d",&u);
		scanf("%d",&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	bit=BIT(MAX);	
}
void readquery(void) {
	REP(i,q) {
		int u,x;
		scanf("%d",&u);
		scanf("%d",&x);	
		qat[u].push_back(ii(x,i));		
	}	
}
void visit(int u) {
	sz[u]=1;
	REP(i,g[u].size()) if (g[u][i]!=p[u]) {
		int v=g[u][i];
		p[v]=u;
		visit(v);
		sz[u]+=sz[v];
	}
}
void changenum(int u,int v) {
	bit.update(cnt[u],-1);
	cnt[u]+=v;
	bit.update(cnt[u],1);	
}
void changedata(int u,int v) {
	changenum(c[u],v);
	REP(i,g[u].size()) if (g[u][i]!=p[u]) changedata(g[u][i],v);
}
void answerq(int u) {	
	if (sz[u]==1) {
		changenum(c[u],1);
		REP(i,qat[u].size()) ans[qat[u][i].se]=(qat[u][i].fi<2);
		return;
	}
	int chid=-1;
	REP(i,g[u].size()) if (g[u][i]!=p[u]) {
		int v=g[u][i];
		if (chid<0 || sz[v]>sz[chid]) chid=v;		
	}
	REP(i,g[u].size()) if (g[u][i]!=p[u] && g[u][i]!=chid) {
		answerq(g[u][i]);
		changedata(g[u][i],-1);
	}
	answerq(chid);
	changenum(c[u],1);
	REP(i,g[u].size()) if (g[u][i]!=p[u] && g[u][i]!=chid) changedata(g[u][i],1);
	REP(i,qat[u].size()) ans[qat[u][i].se]=bit.countgreater(qat[u][i].fi);
}
void process(void) {
	visit(1);
	answerq(1);
	REP(i,q) printf("%d\n",ans[i]);
}
int main(void) {
#ifndef ONLINE_JUDGE
	freopen("tmp.txt","r",stdin);
#endif
	loadtree();
	readquery();
	process();
	return 0;
}
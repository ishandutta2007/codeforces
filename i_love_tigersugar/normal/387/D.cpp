#include<bits/stdc++.h>
#define MAX   555
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define fi   first
#define se   second
using namespace std;
const int INF=(int)1e9+7;
typedef pair<int,int> ii;
vector<ii> edge;
vector<int> g[MAX];
int deg[MAX];
int matx[MAX],maty[MAX],t[MAX];
int n,m;
void minimize(int &x,const int &y) {
	if (x>y) x=y;
}
void init(void) {
	scanf("%d",&n);
	scanf("%d",&m);
	REP(i,m) {
		int u,v;
		scanf("%d",&u);
		scanf("%d",&v);
		edge.push_back(ii(u,v));
		if (u!=v) {
			deg[u]++;
			deg[v]++;
		}
		else deg[u]++;
	}
}
void loadgraph(int x) {
	FOR(i,1,n) g[i].clear();
	FORE(it,edge) if (it->fi!=x && it->se!=x)
		g[it->fi].push_back(it->se);
}
int findway(int s) {
	queue<int> q;
	memset(t,0,sizeof t);	
	q.push(s);
	while (!q.empty()) {
		int u=q.front();q.pop();
		FORE(it,g[u]) {
			int v=*it;
			if (t[v]==0 && matx[u]!=v) {
				t[v]=u;
				if (maty[v]==0) return (v);
				else q.push(maty[v]);
			}		
		}
	}
	return (0);
}
void enlarge(int f) {
	int next,cur;
	cur=f;
	do {
		next=matx[t[cur]];
		matx[t[cur]]=cur;
		maty[cur]=t[cur];
		cur=next;
	}
	while (cur>0);
}
int maxmatching(int x) {
	loadgraph(x);
	memset(matx,0,sizeof matx);
	memset(maty,0,sizeof maty);
	FOR(i,1,n) {
		int t=findway(i);
		if (t>0) enlarge(t);
	}
	int res=0;
	FOR(i,1,n) if (matx[i]>0) res++;
	return (m+3*n-2-2*deg[x]-2*res);
}
void solve(void) {
	int res=INF;
	FOR(i,1,n) minimize(res,maxmatching(i));
	printf("%d",res);
}
int main(void) {
	init();
	solve();
	return 0;
	
}
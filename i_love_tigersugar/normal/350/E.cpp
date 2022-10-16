#include<bits/stdc++.h>
#define MAX   333
using namespace std;
typedef pair<int,int> ii;
vector<int> g[MAX];
set<ii> edge;
set<ii> res;
int mv[MAX];
bool mark[MAX];
bool vst[MAX];
int n,m,k;
int min(const int &x,const int &y) {
	if (x<y) return (x); else return (y);
}
int max(const int &x,const int &y) {
	if (x>y) return (x); else return (y);
}
void loadgraph(void) {
	scanf("%d",&n);
	scanf("%d",&m);
	scanf("%d",&k);
	if (k==n) {
		printf("-1");
		exit(0);
	}
	int i;
	memset(mark,false,sizeof mark);
	memset(vst,false,sizeof vst);
	for (i=1;i<=k;i=i+1) {
		scanf("%d",&mv[i]);
		mark[mv[i]]=true;
	}	
	edge.clear();
	res.clear();
}
void add_edge(const int &u,const int &v) {
	if (u>v) {
		add_edge(v,u);
		return;
	}
	g[u].push_back(v);
	g[v].push_back(u);
	edge.insert(ii(u,v));
}
void DFS(const int &u) {
	int i,v;
	for (i=0;i<g[u].size();i=i+1) {
		v=g[u][i];
		if (!vst[v]) {
			vst[v]=true;			
			res.insert(ii(min(u,v),max(u,v)));
			DFS(v);
		}
	}
}
void process(void) {
	int i,j;
	for (i=1;i<=n;i=i+1)
		for (j=i+1;j<=n;j=j+1)
			if (i!=mv[1] && j!=mv[1] && i!=mv[2] && j!=mv[2])
				add_edge(i,j);
	for (i=1;i<=n;i=i+1) {
		if (!mark[i]) {
			add_edge(i,mv[1]);
			add_edge(i,mv[2]);			
		}
		else if (i!=mv[1] && i!=mv[2]) add_edge(i,mv[1]);
	}
	for (i=1;i<=n;i=i+1)
		if (!vst[i] && !mark[i]) {
			vst[i]=true;
			DFS(i);
		}
}
void answer(void) {
	if (edge.size()<m) {
		printf("-1");
		return;
	}
	set<ii>::iterator it;
	for (it=edge.begin();it!=edge.end();it++) {
		if (res.size()>=m) break;
		res.insert(*it);
	}
	int i=0;
	for (it=res.begin();it!=res.end();it++) {
		i++;
		printf("%d %d\n",(*it).first,(*it).second);
		if (i>=m) break;
	}
}
int main(void) {
	loadgraph();
	process();
	answer();
	return 0;
}
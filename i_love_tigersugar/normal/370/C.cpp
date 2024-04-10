#include<cstdio>
#include<vector>
#include<queue>
#define MAX   5050
using namespace std;
const int INF=(int)1e9+7;
vector<int> g[MAX];
int matx[MAX];
int maty[MAX];
int d[MAX];
int c[MAX];
int n;
void loadgraph(void) {
	scanf("%d",&n);
	int m;
	scanf("%d",&m);
	int i;
	for (i=1;i<=n;i=i+1) scanf("%d",&c[i]);
	for (i=1;i<=n;i=i+1)
		for (int j=i+1;j<=n;j=j+1)
			if (c[i]!=c[j]) {
				g[i].push_back(j);
				g[j].push_back(i);
			}	
}
bool BFS(void) {
	queue<int> q;
	while (!q.empty()) q.pop();
	int i,u,v;
	for (i=1;i<=n;i=i+1) {
		if (matx[i]==0) {
			d[i]=0;
			q.push(i);
		}
		else d[i]=INF;
	}
	d[0]=INF;
	while (!q.empty()) {
		u=q.front();q.pop();
		if (d[u]<d[0])
			for (i=0;i<g[u].size();i=i+1) {
				v=g[u][i];
				if (d[maty[v]]>=INF) {
					d[maty[v]]=d[u]+1;
					q.push(maty[v]);
				}
			}
	}
	return (d[0]<INF);
}
bool DFS(const int &u) {
	if (u==0) return (true);
	int i,v;
	for (i=0;i<g[u].size();i=i+1) {
		v=g[u][i];
		if (d[maty[v]]==d[u]+1)
			if (DFS(maty[v])) {
				matx[u]=v;
				maty[v]=u;
				return (true);
			}		
	}
	d[u]=INF;
	return (false);
}
void fastmatching(void) {
	int i;
	for (i=1;i<=n;i=i+1) matx[i]=0;
	for (i=1;i<=n;i=i+1) maty[i]=0;
	int res=0;
	while (BFS()) {
	//	printf("ok\n");
		for (i=1;i<=n;i=i+1)
			if (matx[i]==0)
				if (DFS(i)) res++;
		//printf("%d\n",res);
	}
	printf("%d\n",res);
	for (i=1;i<=n;i=i+1) {
		if (matx[i]==0) printf("%d %d\n",c[i],c[i]);
		else printf("%d %d\n",c[i],c[matx[i]]);
	}
}
int main(void) {
#ifndef ONLINE_JUDGE
	freopen("tmp.txt","r",stdin);
#endif
	loadgraph();
	fastmatching();
	return 0;
}
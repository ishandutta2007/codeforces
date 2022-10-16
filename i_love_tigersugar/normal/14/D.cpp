#include<bits/stdc++.h>
#define MAX   211
using namespace std;
vector<int> g[MAX];
queue<int> q;
int c[MAX];
int t[MAX];
int l[MAX];
int n,fw,sw,best;
void maximize(int &x,const int &y) {
	if (x<y) x=y;
}
void loadgraph(void) {
	scanf("%d",&n);
	int i,u,v;
	for (i=1;i<n;i=i+1) {
		scanf("%d",&u);
		scanf("%d",&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	best=-1;
}
void BFS_findway(const int &s,const int &f) {
	while (!q.empty()) q.pop();
	memset(c,0,sizeof c);
	q.push(s);
	c[s]=1;
	l[s]=0;
	int i,u,v;
	while (!q.empty()) {
		u=q.front();q.pop();
		if (u==f) {
			fw=l[u];
			//printf("Distance from %d to %d is %d\n",s,f,fw);
			return;
		}
		for (i=0;i<g[u].size();i=i+1) {
			v=g[u][i];
			if (c[v]==0) {
				c[v]=1;
				t[v]=u;
				l[v]=l[u]+1;
				q.push(v);
			}
		}
	}
}
void trace(const int &s,const int &f) {
	int u=f;
	while (u!=s) {
		c[u]=2;
		u=t[u];
	}
	c[s]=2;
	for (u=1;u<=n;u=u+1)
		if (c[u]!=2) c[u]=0;
}
int BFS(const int &s,const int &mode) {
	while (!q.empty()) q.pop();
	c[s]=mode+1;
	l[s]=0;
	q.push(s);
	int i,u,v;
	int md=0;	
	int lp=s;
	while (!q.empty()) {
		u=q.front();q.pop();
		if (md<l[u]) {
			md=l[u];
			lp=u;
		}
		for (i=0;i<g[u].size();i=i+1) {
			v=g[u][i];
			if (c[v]==mode) {
				c[v]=mode+1;
				l[v]=l[u]+1;
				q.push(v);
			}
		}
	}
	if (mode==0) return (lp);
	else return (md);
}
void update(const int &u,const int &v) {
	BFS_findway(u,v);
	trace(u,v);
	int i;
	sw=-1;
	for (i=1;i<=n;i=i+1)
		if (c[i]==0)
			maximize(sw,BFS(BFS(i,0),1));
	maximize(best,fw*sw);
}
void process(void) {
	int i,j;
	for (i=1;i<=n;i=i+1)
		for (j=i;j<=n;j=j+1)
			update(i,j);
	printf("%d",best);
}
int main(void) {
#ifndef ONLINE_JUDGE
	freopen("tmp.txt","r",stdin);
#endif
	loadgraph();
	process();
	return 0;
}
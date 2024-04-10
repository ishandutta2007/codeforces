#include<bits/stdc++.h>
#define MAX   300300
using namespace std;
vector<int> g[MAX];
vector<int> euler;
vector<int> red;
queue<int> q;
int n,m,rb;
int h[MAX];
int c[MAX];
int d[MAX];
bool cl[MAX];
int lg2[MAX];
int dis[MAX];
int fin[MAX];
int rmq[MAX][21];
int min(const int &x,const int &y) {
	if (x<y) return (x); else return (y);
}
int max(const int &x,const int &y) {
	if (x>y) return (x); else return (y);
}
int hmin(const int &x,const int &y) {
	if (h[x]<h[y]) return (x); else return (y);
}
void loadtree(void) {
	scanf("%d",&n);
	scanf("%d",&m);
	int i,u,v;	
	while (rb*rb<n) rb++;
	for (i=1;i<n;i=i+1) {
		scanf("%d",&u);
		scanf("%d",&v);
		g[u].push_back(v);
		g[v].push_back(u);
		dis[i]=-1;
	}
	dis[n]=-1;
	cl[1]=1;
	c[1]=1;	
}
void DFS(const int &u) {
	int i,v;
	for (i=0;i<g[u].size();i=i+1) {
		v=g[u][i];
		if (c[v]==0) {
			c[v]=1;
			h[v]=h[u]+1;
			euler.push_back(u);
			DFS(v);
			euler.push_back(u);			
		}
	}	
	euler.push_back(u);
}
void setup_rmq(void) {
	DFS(1);
	int i,j;
	for (i=0;i<euler.size();i=i+1) {
		j=euler[i];
		if (dis[j]<0) dis[j]=i;
		fin[j]=i;
	}
	for (i=0;i<euler.size();i=i+1) rmq[i][0]=euler[i];
	for (i=1;i<=19;i=i+1)
		for (j=0;j+(1<<i)-1<euler.size();j=j+1)
			rmq[j][i]=hmin(rmq[j][i-1],rmq[j+(1<<(i-1))][i-1]);
	for (i=0;i<euler.size();i=i+1) {	
		while ((1<<lg2[i])<=i) lg2[i]++;
		lg2[i]--;
	}
}
int getmin(const int &i,const int &j) {
	int k=lg2[j-i+1];
	return hmin(rmq[i][k],rmq[j-(1<<k)+1][k]);
}
int lca(const int &u,const int &v) {
	int i=min(dis[u],dis[v]);
	int j=max(fin[u],fin[v]);
	return (getmin(i,j));
}
int distan(const int &u,const int &v) {
	int w=lca(u,v);
	return (h[u]+h[v]-2*h[w]);
}
void rebuild(void) {
	red.clear();
	while (!q.empty()) q.pop();
	int i,u,v;
	for (i=1;i<=n;i=i+1) {
		if (cl[i]) {
			c[i]=1;
			d[i]=0;
			q.push(i);
		}
		else c[i]=0;
	}
	while (!q.empty()) {
		u=q.front();q.pop();
		for (i=0;i<g[u].size();i=i+1) {
			v=g[u][i];
			if (c[v]==0) {
				c[v]=1;
				d[v]=d[u]+1;
				q.push(v);
			}
		}
	}
}
void process(void) {
	int i,j,t,u,r;
	for (i=1;i<=n;i=i+1) d[i]=distan(1,i);
	for (i=1;i<=m;i=i+1) {
		scanf("%d",&t);
		scanf("%d",&u);
		if (t==1) {
			red.push_back(u);
			cl[u]=true;
			if (red.size()>=rb) rebuild();
		}
		else {
			r=d[u];
			for (j=0;j<red.size();j=j+1)
				r=min(r,distan(u,red[j]));
			printf("%d\n",r);
		}
	}
}
int main(void) {
	//freopen("tmp.txt","r",stdin);
	loadtree();	
	setup_rmq();
	process();
	return 0;
}
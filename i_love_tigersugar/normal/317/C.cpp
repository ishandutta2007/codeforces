#include<bits/stdc++.h>
#define MAX   333
using namespace std;
typedef long long ll;
vector<int> g[MAX];
bool con[MAX][MAX];
int a[MAX];
int b[MAX];
int t[MAX];
ll d[MAX];
int n,m;
int up[MAX];
struct trans {
	int x,y,d;
	trans(){}
	trans(const int &_x,const int &_y,const int &_d) {
		x=_x;y=_y;d=_d;
	}
	void print(void) const {
		printf("%d %d %d\n",x,y,d);
	}
};
vector<trans> res;
int min(const int &x,const int &y) {
	if (x<y) return (x); else return (y);
}
int find(const int &x) {
	if (up[x]<0) return (x);
	up[x]=find(up[x]);
	return (up[x]);
}
void join(const int &a,const int &b) {
	int x=find(a);
	int y=find(b);
	if (x==y) return;
	d[x]+=d[y];
	up[y]=x;	
}
void loadgraph(void) {
	scanf("%d",&n);
	scanf("%d",&m);
	scanf("%d",&m);
	int i,u,v;
	for (i=1;i<=n;i=i+1) scanf("%d",&a[i]);
	for (i=1;i<=n;i=i+1) scanf("%d",&b[i]);
	for (i=1;i<=m;i=i+1) {
		scanf("%d",&u);
		scanf("%d",&v);
		if (con[u][v]) continue;
		g[u].push_back(v);
		g[v].push_back(u);
		con[u][v]=true;
		con[v][u]=true;
	}
}
void addtrans(const int &x,const int &y,const int &d) {		
	res.push_back(trans(x,y,d));
	a[x]-=d;
	a[y]+=d;
	assert(res.size()<=2*n*n);
}
void checkans(void) {
	int i,j;
	for (i=1;i<=n;i=i+1) {
		up[i]=-1;
		d[i]=a[i]-b[i];
	}
	for (i=1;i<=n;i=i+1)
		for (j=i+1;j<=n;j=j+1)
			if (con[i][j]) join(i,j);
	for (i=1;i<=n;i=i+1)
		if (up[i]<0 && d[i]!=0LL) {
			printf("NO");
			exit(0);
		}	
}
void findway(const int &s,const int &f) {
	memset(t,0,sizeof t);
	queue<int> q;
	while (!q.empty()) q.pop();
	q.push(s);
	t[s]=-1;
	int i,u,v;
	while (!q.empty()) {
		u=q.front();q.pop();
		if (u==f) return;
		for (i=0;i<g[u].size();i=i+1) {
			v=g[u][i];
			if (t[v]==0) {
				t[v]=u;
				q.push(v);
			}
		}
	}
	assert(false);
}
void transfer(const int &s,const int &f,const int &d) {
	if (s==f) return;
	int u=t[f];
	int del=min(a[u],d);
	int rem=d-del;
	addtrans(u,f,del);
	transfer(s,u,d);
	if (rem>0) addtrans(u,f,rem);
}
bool fill(void) {
	int i,j;
	for (i=1;i<=n;i=i+1)
		if (a[i]>b[i]) break;
	if (i>n) return (false);
	for (j=1;j<=n;j=j+1)
		if (find(i)==find(j) && a[j]<b[j]) break;
	assert(j<=n);
	findway(i,j);
	int d=min(a[i]-b[i],b[j]-a[j]);	
	transfer(i,j,d);	
	return (true);
}
void process(void) {
	while (fill());
	printf("%d\n",res.size());
	int i;
	for (i=0;i<res.size();i=i+1) res[i].print();
}
int main(void) {
	loadgraph();
	checkans();
	process();	
	return 0;
}
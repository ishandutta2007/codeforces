#include<bits/stdc++.h>
#define MAX   500500
#define b   first
#define e   second
using namespace std;
typedef pair<int,int> ii;
vector<int> g[MAX];
bool vst[MAX];
int pos[MAX];
int par[MAX];
ii range[MAX];
int tree[4*MAX];
int mark[4*MAX];
int n,q,cnt;
int min(const int &x,const int &y) {
	if (x<y) return (x); else return (y);
}
void loadtree(void) {
	scanf("%d",&n);
	int i,u,v;
	for (i=1;i<n;i=i+1) {
		scanf("%d",&u);
		scanf("%d",&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}	
}
void visit(const int &u) {
	int i,v;
	cnt++;
	pos[u]=cnt;
	range[u].b=cnt;
	for (i=0;i<g[u].size();i=i+1) {
		v=g[u][i];
		if (!vst[v]) {
			vst[v]=true;
			par[v]=pos[u];
			visit(v);
		}
	}
	range[u].e=cnt;
}
void update(const int &i,const int &l,const int &r,const int &u,const int &v,const int &val) {
	if (l>v) return;
	if (r<u) return;
	if (l>r) return;
	if (u<=l && r<=v) {
		mark[i]=val;
		tree[i]=val;
		return;
	}
	if (mark[i]>-1) {
		mark[2*i]=mark[i];
		tree[2*i]=mark[i];
		mark[2*i+1]=mark[i];
		tree[2*i+1]=mark[i];		
		if (mark[i]!=val) mark[i]=-1;
	}	
	int m=(l+r)/2;
	update(2*i,l,m,u,v,val);
	update(2*i+1,m+1,r,u,v,val);
	tree[i]=min(tree[2*i],tree[2*i+1]);
}
int getmin(const int &i,const int &l,const int &r,const int &u,const int &v) {
	if (l>v) return (2);
	if (r<u) return (2);
	if (l>r) return (2);
	if (u<=l && r<=v) return (tree[i]);
	if (mark[i]>-1) return (mark[i]);
	int m=(l+r)/2;
	int left=getmin(2*i,l,m,u,v);
	int right=getmin(2*i+1,m+1,r,u,v);
	return (min(left,right));
}
void fill(const int &u) {
	int l=range[u].b;
	int r=range[u].e;
	if (u>1 && getmin(1,1,n,l,r)<1) update(1,1,n,par[u],par[u],0);
	update(1,1,n,l,r,1);
}
void empty(const int &u) {
	update(1,1,n,pos[u],pos[u],0);
}
void answer(const int &u) {
	printf("%d\n",getmin(1,1,n,range[u].b,range[u].e));
}
void process(void) {
	int i,t,u;
	vst[1]=true;
	visit(1);
	scanf("%d",&q);
	for (i=1;i<=q;i=i+1) {
		scanf("%d",&t);
		scanf("%d",&u);
		if (t==1) fill(u);
		if (t==2) empty(u);
		if (t==3) answer(u);
	}
}
int main(void) {
	//freopen("tmp.txt","r",stdin);
	loadtree();
	process();
	return 0;
}
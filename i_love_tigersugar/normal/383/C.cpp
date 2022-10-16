#include<bits/stdc++.h>
#define MAX   200200
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
class IT {
	private:
	vector<int> lazy;
	int n;	
	void update(int i,int l,int r,int u,int v,int c) {
		if (l>v) return;
		if (r<u) return;
		if (l>r) return;
		if (v<u) return;
		if (u<=l && r<=v) {
			lazy[i]+=c;
			return;
		}		
		int m=(l+r)>>1;
		update(2*i,l,m,u,v,c);
		update(2*i+1,m+1,r,u,v,c);
	}
	public:
	IT() {
		n=0;
	}
	IT(int n) {
		this->n=n;
		lazy=vector<int>(4*n+7,0);
	}
	void update(int u,int v,int c) {
		update(1,1,n,u,v,c);
	}
	int get(int x) const {
		int i=1;
		int l=1;
		int r=n;
		int ret=0;
		while (true) {
			ret+=lazy[i];
			if (l==r) return (ret);
			int m=(l+r)>>1;
			if (m<x) {
				i=2*i+1;
				l=m+1;
			}
			else {
				i=2*i;
				r=m;
			}
		}
	}
};
IT it[3];
vector<int> g[MAX],v[3];
int a[MAX],h[MAX],p[MAX],id[MAX],l[3][MAX],r[3][MAX];
int n,q;
void loadtree(void) {
	scanf("%d",&n);
	scanf("%d",&q);
	FOR(i,1,n) scanf("%d",&a[i]);
	REP(i,n-1) {
		int u,v;
		scanf("%d",&u);
		scanf("%d",&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	REP(i,2) v[i].push_back(0);
}
void visit(int u) {
	REP(i,2) l[i][u]=v[i].size();
	id[u]=v[h[u]%2].size();
	v[h[u]%2].push_back(u);	
	FORE(it,g[u]) if (*it!=p[u]) {
		p[*it]=u;
		h[*it]=h[u]+1;
		visit(*it);
	}
	REP(i,2) r[i][u]=v[i].size()-1;
}
void update(int u,int v) {
	int t=h[u]%2;
	it[t].update(l[t][u],r[t][u],v);
	t=1-t;
	it[t].update(l[t][u],r[t][u],-v);
}
int answer(int x) {
	return (a[x]+it[h[x]%2].get(id[x]));
}
void process(void) {
	visit(1);
	REP(i,2) it[i]=IT(v[i].size()-1);
	REP(i,q) {
		int t,u,v;
		scanf("%d",&t);
		scanf("%d",&u);
		if (t==1) {
			scanf("%d",&v);
			update(u,v);
		}
		else printf("%d\n",answer(u));
	}
}
int main(void) {
	loadtree();
	process();
	return 0;
}
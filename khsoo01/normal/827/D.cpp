#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef pair<int,int> pii;
const int N = 200005;

int n, m, p[N], dep[N];
pii ans[N];

struct disj {
	int par[N];
	void init() {
		for(int i=1;i<=n;i++) par[i] = i;
	}
	int Find (int X) {
		if(par[X] == X) return X;
		return par[X] = Find(par[X]);
	}
	bool Union (int A, int B) {
		A = Find(A); B = Find(B);
		if(A == B) return false;
		par[A] = B;
		return true;
	}
} uf, pt;

struct edge {
	int a, b, c;
	bool operator < (const edge &T) const {
		if(c != T.c) return c < T.c;
		if(a != T.a) return a < T.a;
		return b < T.b;
	}
};

edge a[N];
vector<edge> edg, swp[N];
vector<int> cp, adj[N];

void calc (int C, int P) {
	dep[C] = dep[P] + 1;
	p[C] = P;
	for(auto &T : adj[C]) {
		if(T == P) continue;
		calc(T, C);
	}
}

void buildMST () {
	uf.init();
	for(auto &T : edg) {
		if(uf.Union(T.a, T.b)) {
			adj[T.a].push_back(T.b);
			adj[T.b].push_back(T.a);
		}
	}
	calc(1, 0);
}

bool solve () {
	for(int i=0;i<cp.size();i++) swp[i].clear();
	for(int i=1;i<=m;i++) {
		if(ans[i].X == ans[i].Y) continue;
		int mid = (ans[i].X + ans[i].Y)/2 + 1;
		swp[mid].push_back({a[i].a, a[i].b, i});
	}
	uf.init(); pt.init();
	for(int i=0,j=0;i<cp.size();i++) {
		while(j<edg.size() && edg[j].c <= i) {
			if(!uf.Union(edg[j].a, edg[j].b)) {
				while(true) {
					int A = pt.Find(edg[j].a), B = pt.Find(edg[j].b);
					if(A == B) break;
					if(dep[A] < dep[B]) swap(A, B);
					pt.Union(A, p[A]);
				}
			} j++;
		}
		for(auto &T : swp[i]) {
			bool flag = false;
			if(uf.Find(T.a) != uf.Find(T.b)) flag = true;
			else if(a[T.c].c <= i && pt.Find(T.a) != pt.Find(T.b)) flag = true;
			flag ? ans[T.c].X = i : ans[T.c].Y = i-1;
		}
	}
	for(int i=1;i<=m;i++) {
		if(ans[i].X != ans[i].Y) return true;
	}
	return false;
}

int main()
{
	scanf("%d%d",&n,&m);
	cp.push_back(0);
	for(int i=1;i<=m;i++) {
		scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
		cp.push_back(a[i].c);
	}
	sort(cp.begin(), cp.end());
	cp.erase(unique(cp.begin(), cp.end()), cp.end());
	for(int i=1;i<=m;i++) {
		a[i].c = lower_bound(cp.begin(), cp.end(), a[i].c) - cp.begin();
		edg.push_back(a[i]);
	}
	sort(edg.begin(), edg.end());
	buildMST();
	for(int i=1;i<=m;i++) ans[i] = pii(0, (int)cp.size()-1);
	while(solve());
	for(int i=1;i<=m;i++) {
		if(ans[i].X + 1 == cp.size()) printf("-1 ");
		else printf("%d ",cp[ans[i].X+1]-1);
	}
	puts("");
}
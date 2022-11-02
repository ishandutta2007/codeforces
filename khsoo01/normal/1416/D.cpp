#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef pair<int,int> pii;

const int N = 200005, M = 300005, Q = 500005;
typedef long long ll;

int n, m, q, p[N], col[N], cc;
pii edg[M], qry[Q];
bool disc[M], off[N];
vector<pair<int, vector<int> > > mv;
priority_queue<int> pq[N];

struct disjoint_set {
	int par[N];
	vector<int> mem[N];
	void init () {
		for(int i=1;i<=n;i++) {
			par[i] = i;
			mem[i].push_back(i);
		}
	}
	int Find (int X) {
		if(par[X] == X) return X;
		return par[X] = Find(par[X]);
	}
	void Union (int A, int B, int I) {
		A = Find(A);
		B = Find(B);
		if(A == B) return;
		if(mem[A].size() < mem[B].size()) swap(A, B);
		mv.push_back({I, mem[B]});
		for(auto &T : mem[B]) {
			mem[A].push_back(T);
		}
		mem[B].clear();
		par[B] = A;
	}
} dsj;

int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++) {
		scanf("%d",&p[i]);
	}
	for(int i=1;i<=m;i++) {
		scanf("%d%d",&edg[i].X,&edg[i].Y);
		edg[i].X = p[edg[i].X];
		edg[i].Y = p[edg[i].Y];
	}
	for(int i=1;i<=q;i++) {
		scanf("%d%d",&qry[i].X,&qry[i].Y);
		if(qry[i].X == 1) qry[i].Y = p[qry[i].Y];
		if(qry[i].X == 2) disc[qry[i].Y] = true;
	}
	dsj.init();
	for(int i=1;i<=m;i++) {
		if(disc[i]) continue;
		dsj.Union(edg[i].X, edg[i].Y, q+1);
	}
	for(int i=q;i>=1;i--) {
		if(qry[i].X == 1) continue;
		int I = qry[i].Y;
		dsj.Union(edg[I].X, edg[I].Y, i);
	}
	for(int i=1;i<=n;i++) {
		if(dsj.Find(i) != i) continue;
		++cc;
		for(auto &T : dsj.mem[i]) {
			col[T] = cc;
			pq[cc].push(T);
		}
	}
	for(int i=1;i<=q;i++) {
		while(!mv.empty() && mv.back().X <= i) {
			++cc;
			for(auto &T : mv.back().Y) {
				col[T] = cc;
				if(!off[T]) pq[cc].push(T);
			}
			mv.pop_back();
		}
		if(qry[i].X == 2) continue;
		int X = col[qry[i].Y];
		while(true) {
			if(pq[X].empty()) {
				puts("0");
				break;
			}
			int T = pq[X].top();
			pq[X].pop();
			if(col[T] != X) continue;
			printf("%d\n", T);
			off[T] = true;
			break;
		}
	}
}
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 100005, L = 131072;

struct node {
	node() {v=l=r=0;}
	ll v;
	int l, r;
};

struct segtree {
	vector<node> nd;
	set<int> s;
	void init () {
		nd.push_back(node());
		nd.push_back(node());
	}
	void clear () {
		nd.clear();
		s.clear();
	}
	ll qry (int I, int SS = 0, int SE = L-1, int P = 1) {
		ll R = nd[P].v;
		if(SS == SE) return R;
		int M = (SS+SE)/2;
		if(I <= M) R += qry(I, SS, M, nd[P].l);
		else R += qry(I, M+1, SE, nd[P].r);
		return R;
	}
	void upd (int S, int E, ll X, int SS = 0, int SE = L-1, int P = 1) {
		if(S <= SS && SE <= E) {
			nd[P].v += X;
			return;
		}
		if(E < SS || SE < S) return;
		if(!nd[P].l) {
			nd[P].l = nd.size();
			nd.push_back(node());
		}
		if(!nd[P].r) {
			nd[P].r = nd.size();
			nd.push_back(node());
		}
		int M = (SS+SE)/2;
		upd(S, E, X, SS, M, nd[P].l);
		upd(S, E, X, M+1, SE, nd[P].r);
	}
	void upd (int P, ll V) {
		s.insert(P);
		ll C = qry(P);
		while(true) {
			auto it = s.find(P);
			it++;
			int B = (it == s.end() ? L-1 : *it-1);
			ll NV = (it == s.end() ? 0 : qry(*it));
			if(it == s.end() || NV > V) {
				upd(P, B, V - C);
				break;
			}
			else {
				upd(P, B, NV - C);
				C = NV;
				s.erase(it);
			}
		}
	}
} seg[N];

int n, m, a[N], b[N];

vector<int> adj[N];

void solve (int I) {
	seg[I].init();
	for(auto &T : adj[I]) {
		solve(T);
		if(seg[I].s.size() < seg[T].s.size()) swap(seg[I], seg[T]);
		for(auto V : seg[T].s) {
			auto it = seg[T].s.upper_bound(V);
			seg[I].upd(V, (it == seg[T].s.end() ? L-1 : *it-1), seg[T].qry(V));
			seg[I].s.insert(V);
		}
		seg[T].clear();
	}
	if(b[I]) seg[I].upd(a[I], seg[I].qry(a[I]) + b[I]);
}

int main()
{
	scanf("%d%d%*d",&n,&m);
	for(int i=2;i<=n;i++) {
		int T;
		scanf("%d",&T);
		adj[T].push_back(i);
	}
	for(int i=1;i<=m;i++) {
		int I, A, B;
		scanf("%d%d%d",&I,&A,&B);
		a[I] = A;
		b[I] = B;
	}
	solve(1);
	printf("%lld\n", seg[1].qry(L-1));
}
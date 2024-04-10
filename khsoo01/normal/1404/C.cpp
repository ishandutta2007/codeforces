#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
const int N = 300005, L = (1<<19), inf = 1e8;

struct segtree {
	int v[2*L], l[2*L];
	void init () {
		for(int i=2*L;--i;) {
			v[i] = inf;
		}
	}
	void lazydown (int P) {
		v[2*P] += l[P];
		v[2*P+1] += l[P];
		l[2*P] += l[P];
		l[2*P+1] += l[P];
		l[P] = 0;
	}
	void upd (int S, int E, int X, int SS = 0, int SE = L-1, int P = 1) {
		if(S <= SS && SE <= E) {
			v[P] += X;
			l[P] += X;
			return;
		}
		if(S > SE || SS > E) return;
		lazydown(P);
		int M = (SS+SE)/2;
		upd(S, E, X, SS, M, 2*P);
		upd(S, E, X, M+1, SE, 2*P+1);
		v[P] = min(v[2*P], v[2*P+1]);
	}
	pii findmin (int SS = 0, int SE = L-1, int P = 1) {
		if(SS == SE) return {SS, v[P]};
		lazydown(P);
		int M = (SS+SE)/2;
		if(v[2*P] < v[2*P+1]) return findmin(SS, M, 2*P);
		else return findmin(M+1, SE, 2*P+1);
	}
} seg;

struct sumseg {
	int v[2*L];
	void upd (int P, int V) {
		P += L;
		v[P] += V;
		P /= 2;
		while(P) {
			v[P] += V;
			P /= 2;
		}
	}
	int get (int S, int E) {
		S += L;
		E += L;
		int R = 0;
		while(S <= E) {
			if(S%2 == 1) R += v[S++];
			if(E%2 == 0) R += v[E--];
			S /= 2;
			E /= 2;
		}
		return R;
	}
} sseg;

int n, q, a[N], mi[N], ans[N];
vector<int> swp[N];
vector<pii> qry[N];

int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
	}
	seg.init();
	for(int i=n;i>=1;i--) {
		int D = i - a[i];
		if(D >= 0) seg.upd(i, i, D-inf);
		while(true) {
			int I, V;
			tie(I, V) = seg.findmin();
			if(V > 0) break;
			mi[I] = i;
			seg.upd(I, I, inf);
			seg.upd(I+1, n, -1);
		}
	}
	for(int i=1;i<=n;i++) {
		swp[mi[i]].push_back(i);
	}
	for(int i=1;i<=q;i++) {
		int A, B;
		scanf("%d%d",&A,&B);
		int S = A+1, E = n-B;
		qry[S].push_back({E, i});
	}
	for(int i=n;i>=1;i--) {
		for(auto &T : swp[i]) {
			sseg.upd(T, 1);
		}
		for(auto &T : qry[i]) {
			int E, I;
			tie(E, I) = T;
			ans[I] = sseg.get(i, E);
		}
	}
	for(int i=1;i<=q;i++) {
		printf("%d\n", ans[i]);
	}
}
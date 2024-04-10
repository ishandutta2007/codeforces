#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

const int N = 300005, L = 524288;
typedef long long ll;
typedef pair<int,int> pii;

ll ans;

map<pii, int> s;
int q;

struct disjoint_set {
	int par[2*N], rnk[2*N], xs[2*N], ys[2*N];
	void init () {
		iota(par, par+2*N, 0);
		for(int i=0;i<2*N;i++) {
			if(i < N) xs[i]++;
			else ys[i]++;
		}
	}
	int Find (int X) {
		while(par[X] != X) X = par[X];
		return X;
	}
	bool Union (int A, int B, vector<pii> &V) {
		A = Find(A); B = Find(B);
		if(A == B) return false;
		if(rnk[A] < rnk[B]) swap(A, B);
		ans -= 1ll * xs[A] * ys[A] + 1ll * xs[B] * ys[B];
		if(xs[B]) {
			V.push_back({B, xs[B]});
			V.push_back({A, -xs[B]});
			xs[A] += xs[B];
			xs[B] = 0;
		}
		if(ys[B]) {
			V.push_back({-B, ys[B]});
			V.push_back({-A, -ys[B]});
			ys[A] += ys[B];
			ys[B] = 0;
		}
		ans += 1ll * xs[A] * ys[A];
		if(rnk[A] == rnk[B]) {
			V.push_back({A, 0});
			rnk[A]++;
		}
		V.push_back({-B, 0});
		par[B] = A;
		return true;
	}
	void revert (vector<pii> &V) {
		for(int i=V.size();i--;) {
			int A, B;
			tie(A, B) = V[i];
			if(!B) {
				if(A > 0) rnk[A]--;
				else par[-A] = -A;
			}
			else {
				if(A > 0) {
					ans += 1ll * B * ys[A];
					xs[A] += B;
				}
				else {
					ans += 1ll * B * xs[-A];
					ys[-A] += B;
				}
			}
		}
	}
} dsu;

struct segtree {
	vector<pii> v[2*L];
	void upd (int S, int E, pii V) {
		S += L; E += L;
		while(S <= E) {
			if(S%2 == 1) v[S++].push_back(V);
			if(E%2 == 0) v[E--].push_back(V);
			S /= 2; E /= 2;
		}
	}
	void solve (int P = 1) {
		vector<pii> V;
		for(auto &T : v[P]) {
			int A, B;
			tie(A, B) = T;
			dsu.Union(A, B, V);
		}
		if(P >= L) {
			if(P - L < q) printf("%lld ", ans);
		}
		else {
			solve(2*P);
			solve(2*P+1);
		}
		dsu.revert(V);
	}
} seg;

int main()
{
	scanf("%d",&q);
	for(int i=0;i<q;i++) {
		pii T;
		scanf("%d%d",&T.X,&T.Y);
		T.Y += N;
		if(s[T]) {
			seg.upd(s[T]-1, i-1, T);
			s[T] = 0;
		}
		else s[T] = i+1;
	}
	for(auto &T : s) {
		pii A; int B;
		tie(A, B) = T;
		if(B) seg.upd(B-1, q-1, A);
	}
	dsu.init();
	seg.solve();
}
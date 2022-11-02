#include<bits/stdc++.h>
using namespace std;

const int N = 200005, L = 262144, G = 18, inf = 1e9;
int n, a[N], ans[N];

struct segtree {
	int v[2*L];
	void upd (int P, int V) {
		P += L;
		v[P] = V;
		P /= 2;
		while(P) {
			v[P] = max(v[2*P], v[2*P+1]);
			P /= 2;
		}
	}
	int get (int S, int E) {
		S += L; E += L;
		int R = -inf;
		while(S <= E) {
			if(S%2 == 1) {R = max(R, v[S]); S++;}
			if(E%2 == 0) {R = max(R, v[E]); E--;}
			S /= 2; E /= 2;
		}
		return R;
	}
} s[G], e[G];

int main()
{
	scanf("%d",&n);
	if(n == 1) {
		puts("0");
		return 0;
	}
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		a[i+n] = a[i];
	}
	n *= 2;
	for(int i=1;i<=n;i++) {
		s[0].upd(i, -max(1, i-a[i]));
		e[0].upd(i, min(n, i+a[i]));
	}
	for(int i=1;i<G;i++) {
		for(int j=1;j<=n;j++) {
			int A = max(1, -s[i-1].get(j,j)), B = min(n, e[i-1].get(j,j));
			s[i].upd(j, s[i-1].get(A, B));
			e[i].upd(j, e[i-1].get(A, B));
		}
	}
	for(int i=1;i<=n/2;i++) {
		ans[i] = inf;
	}
	for(int i=1;i<=n;i++) {
		int X = 0, A = i, B = i;
		for(int j=G;j--;) {
			int NA = -s[j].get(A, B), NB = e[j].get(A, B);
			if(NB - NA + 1 < n/2) {
				X += (1<<j);
				A = NA; B = NB;
			}
		}
		int I = i > n/2 ? i-n/2 : i;
		ans[I] = min(ans[I], X+1);
	}
	for(int i=1;i<=n/2;i++) {
		printf("%d ",ans[i]);
	}
}
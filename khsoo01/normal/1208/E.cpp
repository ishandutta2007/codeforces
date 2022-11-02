#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1000005, L = (1<<20), inf = 2e9;

int n, w, m, a[N];
ll s[N];

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
	int get (int S, int E){
		int R = -inf;
		S += L; E += L;
		while(S<=E) {
			if(S%2 == 1) R = max(R, v[S++]);
			if(E%2 == 0) R = max(R, v[E--]);
			S /= 2; E /= 2;
		}
		return R;
	}
} seg;

void solve () {
	scanf("%d",&m);
	m += 2;
	int MX = min(w - m + 1, m);
	seg.upd(1, 0);
	seg.upd(m, 0);
	for(int i=2;i<=m-1;i++) {
		scanf("%d",&a[i]);
		seg.upd(i, a[i]);
	}
	int C = 1, E = 1;
	for(int i=1;i<=w;) {
		int j;
		int T = seg.get(E - C + 1, E);
		if(E < m) {
			j = i+1;
			E++;
			C = min(MX, C+1);
		}
		else {
			if(C == MX) j = w - (MX-1) + 1;
			else j = i+1;
			C--;
		}
		s[i] += T;
		s[j] -= T;
		i = j;
	}
}

int main()
{
	scanf("%d%d",&n,&w);
	w += 2;
	for(int i=1;i<=n;i++) solve();
	for(int i=2;i<=w-1;i++) {
		s[i] += s[i-1];
		printf("%lld ", s[i]);
	}
	puts("");
}
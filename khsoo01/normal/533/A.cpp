#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef pair<int,int> pii;

const int N = 500005, L = 524288, inf = 1e9+7;

int n, m, a[N], l[N], r[N], cc, ans = inf;

vector<int> adj[N], wrk, piv;
vector<pii> cav;

void push (vector<pii> &V, pii &X) {
	V.push_back(X);
	for(int i=(int)V.size()-1;i>0;i--) {
		if(V[i-1] > V[i]) swap(V[i-1], V[i]);
		else break;
	}
	if(V.size() > 2) V.pop_back();
}

struct segtree {
	vector<pii> v[2*L];
	void upd (int S, int E, pii X) {
		S += L;
		E += L;
		while(S <= E) {
			if(S%2 == 1) push(v[S++], X);
			if(E%2 == 0) push(v[E--], X);
			S /= 2;
			E /= 2;
		}
	}
	pii get (int P) {
		vector<pii> R;
		R.push_back({inf, 0});
		P += L;
		while(P) {
			for(auto &T : v[P]) {
				push(R, T);
			}
			P /= 2;
		}
		return {R[0].Y, R[1].Y};
	}
} seg;

void calc (int C, int P) {
	l[C] = ++cc;
	for(auto &T : adj[C]) {
		if(T == P) continue;
		calc(T, C);
	}
	r[C] = cc;
}

bool cmp (pii &A, pii &B) {
	if(A.X != B.X) {
		if(a[A.X] != a[B.X]) return a[A.X] < a[B.X];
		return A.X < B.X;
	}
	if(A.Y != B.Y) {
		if(a[A.Y] != a[B.Y]) return a[A.Y] < a[B.Y];
		return A.Y < B.Y;
	}
	return false;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
	}
	a[0] = inf;
	for(int i=1;i<n;i++) {
		int A, B;
		scanf("%d%d",&A,&B);
		adj[A].push_back(B);
		adj[B].push_back(A);
	}
	calc(1, 0);
	l[0] = 0;
	r[0] = n;
	for(int i=0;i<=n;i++) {
		seg.upd(l[i], r[i], {a[i], i});
	}
	for(int i=0;i<=n;i++) {
		cav.push_back(seg.get(l[i]));
	}
	sort(cav.begin(), cav.end(), cmp);
	scanf("%d",&m);
	for(int i=0;i<n-m;i++) {
		wrk.push_back(0);
	}
	for(int i=1;i<=m;i++) {
		int T;
		scanf("%d",&T);
		wrk.push_back(T);
	}
	sort(wrk.begin(), wrk.end());
	int F = -1, O = 0;
	for(int i=0;i<n;i++) {
		if(wrk[i] > a[cav[i].X]) {
			F = i;
			break;
		}
	}
	if(F == -1) {
		puts("0");
		return 0;
	}
	for(int i=n-1;i>=0;) {
		int k = i;
		while(k > 0 && cav[k-1].X == cav[i].X) {
			k--;
		}
		if(O == 0) {
			if(F >= k && wrk[i] <= a[cav[i].Y]) {
				int V = wrk[i] - a[cav[i].X];
				bool Z = true;
				for(int j=k;j<=i;j++) {
					if(wrk[j] > a[cav[j].Y]) {
						Z = false;
						break;
					}
				}
				if(Z) ans = min(ans, V);
			}
		}
		else if(F >= k && i-k+1 >= O && wrk[piv[0]] <= a[cav[i].Y]) {
			int V = wrk[piv[0]] - a[cav[i].X];
			bool Z = true;
			vector<int> B;
			for(int j=i-O;j>=k;j--) {
				B.push_back(a[cav[j].Y]);
			}
			for(int j=1;j<=O;j++) {
				B.push_back(a[cav[i+j].X]);
			}
			sort(B.begin(), B.end());
			for(int j=0;j<i-k+1;j++) {
				if(wrk[k+j] > B[j]) {
					Z = false;
					break;
				}
			}
			if(Z) {
				for(int j=0;j<O;j++) {
					if(wrk[piv[j]] > a[cav[i].Y]) {
						Z = false;
						break;
					}
				}
				if(Z) ans = min(ans, V);
			}
		}
		for(int j=i;j>=k;j--) {
			int S = 0, E = O+1;
			while(S<E) {
				int M = (S+E)/2;
				a[cav[j+M].X] >= wrk[j] ? E = M : S = M+1;
			}
			if(S == O+1) {
				piv.push_back(j);
				O++;
			}
		}
		i = k-1;
	}
	printf("%d\n", ans == inf ? -1 : ans);
}
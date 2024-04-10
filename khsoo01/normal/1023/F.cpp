#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

typedef pair<int,int> pii;
const int N = 500005, G = 19;

int n, k, m, p[N], s[N], e[N], dep[N], par[G][N], v[N], cc;

bool bl[N];

vector<pii> adj[N];
vector<pair<int, pii> > edg;

int Find (int X) {
	if(p[X] == X) return X;
	return p[X] = Find(p[X]);
}

void calc (int C, int P) {
	s[C] = ++cc;
	dep[C] = dep[P] + 1;
	par[0][C] = P;
	for(auto &T : adj[C]) {
		int A, B;
		tie(A, B) = T;
		if(A == P) continue;
		if(B) bl[A] = true;
		calc(A, C);
	}
	e[C] = cc;
}

int getlca (int A, int B) {
	if(dep[A] > dep[B]) swap(A, B);
	for(int i=G;i--;) {
		if(dep[B] - dep[A] >= (1<<i)) B = par[i][B];
	}
	if(A == B) return A;
	for(int i=G;i--;) {
		if(par[i][A] != par[i][B]) {
			A = par[i][A];
			B = par[i][B];
		}
	}
	return par[0][A];
}

int main()
{
	scanf("%d%d%d",&n,&k,&m);
	iota(p+1, p+1+n, 1);
	for(int i=1;i<=k;i++) {
		int A, B;
		scanf("%d%d",&A,&B);
		adj[A].push_back({B, 0});
		adj[B].push_back({A, 0});
		p[Find(B)] = Find(A);
	}
	while(m--) {
		int A, B, C;
		scanf("%d%d%d",&A,&B,&C);
		if(Find(A) != Find(B)) {
			adj[A].push_back({B, 1});
			adj[B].push_back({A, 1});
			p[Find(B)] = Find(A);
		}
		else edg.push_back({C, {A, B}});
	}
	calc(1, 0);
	for(int i=1;i<G;i++) {
		for(int j=1;j<=n;j++) {
			par[i][j] = par[i-1][par[i-1][j]];
		}
	}
	iota(p+1, p+1+n, 1);
	for(auto &T : edg) {
		int A = T.Y.X, B = T.Y.Y, V = T.X;
		int C = getlca(A, B);
		while(true) {
			A = Find(A);
			B = Find(B);
			if(A == B) break;
			if(dep[A] > dep[B]) swap(A, B);
			v[B] = V;
			p[B] = par[0][B];
		}
	}
	long long ans = 0;
	for(int i=2;i<=n;i++) {
		if(bl[i]) continue;
		if(!v[i]) {
			puts("-1");
			return 0;
		}
		ans += v[i];
	}
	printf("%lld\n",ans);
}
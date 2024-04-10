#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>

using namespace std;

typedef unsigned uint;
typedef long long Int;
typedef vector<int> vint;
typedef pair<int,int> pint;
#define mp make_pair

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in() { int x; scanf("%d", &x); return x; }

int N, K;
int X[1010], Y[1010];
int D[1010][1010];

bool chosen[1010];
bool G[1010][1010];
int deg[1010];
int m, ptr[1010], next[10010], zu[10010];
int psLen;
pint ps[1010];
int flg[1010];

bool dfs(int k, int j) {
	if (k < 0) {
		return 0;
	}
	if (j == psLen) {
		return 1;
	}
	int u = ps[j].second;
	if (flg[u]) {
		return dfs(k, j + 1);
	}
	int i, v;
	int cnt = 0;
	for (i = ptr[u]; ~i; i = next[i]) {
		v = zu[i];
		if (!flg[v]) {
			++cnt;
		}
	}
	
	//	do not use u
	{
		vint updated;
		int kk = k;
		flg[u] = -1;
		for (i = ptr[u]; ~i; i = next[i]) {
			v = zu[i];
			if (!flg[v]) {
				--kk;
				flg[v] = +1;
				updated.push_back(v);
			}
		}
		if (dfs(kk, j + 1)) {
			return 1;
		}
		flg[u] = 0;
		for (vint::iterator it = updated.begin(), en = updated.end(); it != en; ++it) {
			flg[*it] = 0;
		}
	}
	
	//	use u
	if (cnt != 1) {
		int kk = k;
		--kk;
		flg[u] = +1;
		if (dfs(kk, j + 1)) {
			return 1;
		}
		flg[u] = 0;
	}
	
	return 0;
}

bool solve(int dLim) {
// cout<<"solve "<<dLim<<endl;
	int u, v;
	memset(chosen, 0, N);
	memset(G, 0, sizeof(G));
	for (u = 0; u < N; ++u) for (v = 0; v < N; ++v) {
		G[u][v] = (D[u][v] > dLim);
	}
	int E = 0;
	memset(deg, 0, N << 2);
	for (u = 0; u < N; ++u) for (v = 0; v < N; ++v) if (G[u][v]) {
		++E;
		++deg[u];
	}
	E /= 2;
	int k = K;
	for (bool cont = 1; cont; ) {
		if (k < 0) break;
		cont = 0;
		for (u = 0; u < N; ++u) if (deg[u] > k) {
			cont = 1;
			--k;
			chosen[u] = 1;
			for (v = 0; v < N; ++v) if (G[u][v]) {
				G[u][v] = G[v][u] = 0;
				--E;
				--deg[u];
				--deg[v];
			}
		}
	}
	if (k < 0 || E > k * k) {
		return 0;
	}
// cout<<"first chosen : ";pv(chosen,chosen+N);
	m = 0;
	memset(ptr, ~0, N << 2);
	for (u = 0; u < N; ++u) for (v = 0; v < N; ++v) if (G[u][v]) {
		next[m] = ptr[u]; ptr[u] = m; zu[m] = v; ++m;
	}
if(0){
cout<<"graph"<<endl;
for(u=0;u<N;++u){cout<<u<<": ";for(int i=ptr[u];~i;i=next[i])cout<<zu[i]<<" ";cout<<endl;}
cout<<" k = "<<k<<endl;
}
	psLen = 0;
	for (u = 0; u < N; ++u) if (!chosen[u]) {
		ps[psLen++] = mp(deg[u], u);
	}
	sort(ps, ps + psLen, greater<pint>());
	memset(flg, 0, N << 2);
	bool res = dfs(k, 0);
	if (!res) {
		return 0;
	}
	for (u = 0; u < N; ++u) if (flg[u] == +1) {
		chosen[u] = 1;
	}
assert(count(chosen,chosen+N,true)<=K);
// cout<<"VC succeeded"<<endl;
	return 1;
}

int dsLen;
int ds[500010];

int ansLen;
int ans[1010];

int main() {
	int u, v;
	
	for (; ~scanf("%d%d", &N, &K); ) {
		for (u = 0; u < N; ++u) {
			X[u] = in();
			Y[u] = in();
		}
		for (u = 0; u < N; ++u) for (v = 0; v < N; ++v) {
			D[u][v] = (X[u] - X[v]) * (X[u] - X[v]) + (Y[u] - Y[v]) * (Y[u] - Y[v]);
		}
		dsLen = 0;
		ds[dsLen++] = 0;
		for (u = 0; u < N; ++u) for (v = u + 1; v < N; ++v) {
			ds[dsLen++] = D[u][v];
		}
		sort(ds, ds + dsLen);
		dsLen = unique(ds, ds + dsLen) - ds;
		int lo = -1, ho = dsLen - 1;
		for (; lo + 1 < ho; ) {
			int mo = (lo + ho) / 2;
			solve(ds[mo]) ? (ho = mo) : (lo = mo);
		}
// cout<<"diameter^2 = "<<ds[ho]<<endl;
		solve(ds[ho]);
		ansLen = 0;
		for (u = 0; u < N; ++u) if (chosen[u]) {
			ans[ansLen++] = u;
		}
		for (u = 0; u < N; ++u) if (!chosen[u]) {
			if (ansLen < K) {
				ans[ansLen++] = u;
			}
		}
assert(ansLen==K);
		for (int j = 0; j < ansLen; ++j) {
			if (j) printf(" ");
			printf("%d", ans[j] + 1);
		}
		puts("");
	}
	
	return 0;
}
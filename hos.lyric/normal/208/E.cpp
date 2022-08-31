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

#define MAX 200010
const int E = 20;

int N, Q;
int par[MAX];
int m, ptr[MAX], next[MAX], zu[MAX];
int Z, dis[MAX], fin[MAX], dep[MAX];
vector<vint> us;
int P[25][MAX];

void dfs(int u, int d) {
	dis[u] = Z++;
	dep[u] = d;
	int i;
	for (i = ptr[u]; ~i; i = next[i]) {
		dfs(zu[i], d + 1);
	}
	fin[u] = Z++;
}

int getParent(int l, int u) {
	int e;
	for (e = 0; e < E; ++e) if (l & 1 << e) {
		u = P[e][u];
	}
	return u;
}

int main() {
	int u, v;
	int d, l;
	int e;
	int q;
	
	for (; ~scanf("%d", &N); ) {
		for (v = 0; v < N; ++v) {
			par[v] = in() - 1;
		}
		m = 0;
		memset(ptr, ~0, N << 2);
		for (v = 0; v < N; ++v) if (~par[v]) {
			u = par[v];
			next[m] = ptr[u]; ptr[u] = m; zu[m] = v; ++m;
		}
		Z = 0;
		memset(dis, ~0, N << 2);
		for (u = 0; u < N; ++u) if (!~dis[u]) {
			dfs(u, 0);
		}
		us = vector<vint>(N);
		for (u = 0; u < N; ++u) {
			us[dep[u]].push_back(dis[u]);
		}
		for (d = 0; d < N; ++d) {
			sort(us[d].begin(), us[d].end());
// cout<<"us["<<d<<"] : ";pv(us[d].begin(),us[d].end());
		}
		for (u = 0; u < N; ++u) {
			P[0][u] = ~par[u] ? par[u] : N;
		}
		P[0][N] = N;
		for (e = 0; e < E; ++e) {
			for (u = 0; u <= N; ++u) {
				P[e + 1][u] = P[e][ P[e][u] ];
			}
		}
		Q = in();
		for (q = 0; q < Q; ++q) {
			if (q) printf(" ");
			u = in() - 1;
			l = in();
			d = dep[u];
			if (d - l < 0) {
				printf("0");
				continue;
			}
			int ans = 0;
			v = getParent(l, u);
assert(v!=N);
			ans += upper_bound(us[d].begin(), us[d].end(), fin[v]) - lower_bound(us[d].begin(), us[d].end(), dis[v]);
			v = getParent(l - 1, u);
assert(v!=N);
			// ans -= upper_bound(us[d].begin(), us[d].end(), fin[v]) - lower_bound(us[d].begin(), us[d].end(), dis[v]);
ans-=1;
// assert(dis[getParent(l,u)]<dis[v]&&fin[v]<fin[getParent(l,u)]);
			printf("%d", ans);
		}
		puts("");
	}
	
	return 0;
}
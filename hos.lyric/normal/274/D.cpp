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

#define MAX 1000010

int M, N;
vector<vint> A;

int V;
int m, ptr[MAX], next[MAX], zu[MAX];
int psLen;
pint ps[MAX];

void ae(int u, int v) {
// cout<<"ae "<<u<<" "<<v<<endl;
	next[m] = ptr[u]; ptr[u] = m; zu[m] = v; ++m;
}

int vis[MAX];
int ordLen;
int ord[MAX];
bool dfs(int u) {
	int i, v;
	vis[u] = 1;
	for (i = ptr[u]; ~i; i = next[i]) {
		v = zu[i];
		if (~vis[v]) {
			if (vis[v]) return 0;
			if (!dfs(v)) return 0;
		}
	}
	vis[u] = -1;
	ord[ordLen++] = u;
	return 1;
}

void tSort() {
	int i, u;
	memset(vis, 0, V << 2);
	ordLen = 0;
	for (u = 0; u < V; ++u) if (!vis[u]) {
		if (!dfs(u)) {
			break;
		}
	}
	if (u < V) {
		puts("-1");
		return;
	}
	reverse(ord, ord + ordLen);
	int ou = 0;
	for (i = 0; i < ordLen; ++i) {
		u = ord[i];
		if (u < N) {
			if (ou++) printf(" ");
			printf("%d", u + 1);
		}
	}
	puts("");
}

int main() {
	int x, y, z, w;
	
	for (; ~scanf("%d%d", &M, &N); ) {
		A = vector<vint>(M, vint(N));
		for (x = 0; x < M; ++x) for (y = 0; y < N; ++y) {
			A[x][y] = in();
		}
		V = N;
		m = 0;
		memset(ptr, ~0, sizeof(ptr));
		for (x = 0; x < M; ++x) {
			psLen = 0;
			for (y = 0; y < N; ++y) if (A[x][y] != -1) {
				ps[psLen++] = mp(A[x][y], y);
			}
			sort(ps, ps + psLen);
// cout<<"ps : ";for(y=0;y<psLen;++y)cout<<"("<<ps[y].first<<", "<<ps[y].second<<") ";cout<<endl;
			++V;
			for (y = 0; y < psLen; y = z) {
				for (z = y; z < psLen && ps[y].first == ps[z].first; ++z);
				++V;
				for (w = y; w < z; ++w) {
					ae(V - 2, ps[w].second);
					ae(ps[w].second, V - 1);
				}
			}
		}
		tSort();
	}
	
	return 0;
}
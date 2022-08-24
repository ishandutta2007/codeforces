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

#define MAXN 100010
#define MAXM 100010

int N, M;
int F[MAXN];
int ptr[2][MAXN], next[2][MAXM], zu[2][MAXM];

bool vis[2][MAXN];

void dfs(int s, int u, int forbidden = -1) {
// cout<<"dfs "<<s<<" "<<u<<" "<<forbidden<<endl;
	if (vis[s][u]) return;
	vis[s][u] = 1;
	if (F[u] == forbidden) return;
	int i, v;
	for (i = ptr[s][u]; ~i; i = next[s][i]) {
		v = zu[s][i];
		dfs(s, v, forbidden);
	}
}

int main() {
	int i, u, v;
	
	for (; ~scanf("%d%d", &N, &M); ) {
		for (u = 0; u < N; ++u) {
			F[u] = in();
		}
		memset(ptr, ~0, sizeof(ptr));
		for (i = 0; i < M; ++i) {
			u = in() - 1;
			v = in() - 1;
			next[0][i] = ptr[0][u]; ptr[0][u] = i; zu[0][i] = v;
			next[1][i] = ptr[1][v]; ptr[1][v] = i; zu[1][i] = u;
		}
		memset(vis, 0, sizeof(vis));
		for (u = 0; u < N; ++u) if (F[u] == 1) {
			dfs(0, u);
		}
		for (u = 0; u < N; ++u) if (F[u] == 2) {
			dfs(1, u, 1);
		}
		for (u = 0; u < N; ++u) {
			printf("%d\n", (vis[0][u] && vis[1][u]) ? 1 : 0);
		}
	}
	
	return 0;
}
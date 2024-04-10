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
#include <deque>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef unsigned uint;
typedef long long Int;
typedef vector<int> vint;
typedef pair<int,int> pint;
#define mp make_pair

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T &t, const T &f) { if (t > f) t = f; }
template<typename T> void chmax(T &t, const T &f) { if (t < f) t = f; }
int in() { int x; scanf("%d", &x); return x; }

int M, N, V, W;
char A[1010][20][20];
int D[1010][1010];

int ds[1010];
int prv[1010];
bool used[1010];

int ansLen;
pint ans[1010];

int main() {
	
	
	for (; ~scanf("%d%d%d%d", &M, &N, &V, &W); ) {
		for (int u = 0; u < V; ++u) {
			for (int x = 0; x < M; ++x) {
				scanf("%s", A[u][x]);
			}
		}
		for (int u = 0; u < V; ++u) for (int v = u + 1; v < V; ++v) {
			int cnt = 0;
			for (int x = 0; x < M; ++x) for (int y = 0; y < N; ++y) {
				if (A[u][x][y] != A[v][x][y]) {
					++cnt;
				}
			}
			D[u][v] = D[v][u] = cnt * W;
		}
		fill_n(ds, V, M * N);
		fill_n(used, V, false);
		fill_n(prv, V, -1);
		int total = 0;
		ansLen = 0;
		for (; ; ) {
			int um = -1;
			for (int u = 0; u < V; ++u) if (!used[u]) {
				if (!~um || ds[um] > ds[u]) {
					um = u;
				}
			}
			if (!~um) {
				break;
			}
// cout<<"um = "<<um<<endl;
			used[um] = true;
			total += ds[um];
			ans[ansLen++] = mp(um, prv[um]);
			for (int v = 0; v < V; ++v) {
				if (ds[v] > D[um][v]) {
					ds[v] = D[um][v];
					prv[v] = um;
				}
			}
		}
		printf("%d\n", total);
		for (int i = 0; i < ansLen; ++i) {
			printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
		}
	}
	
	return 0;
}
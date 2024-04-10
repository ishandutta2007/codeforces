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
template<class T> void chmin(T &t, const T &f) { if (t > f) t = f; }
template<class T> void chmax(T &t, const T &f) { if (t < f) t = f; }
int in() { int x; scanf("%d", &x); return x; }

int N, P;
vector<vint> G;
int deg[300010];

int bit[300010];
void bitAdd(int pos, int val) {
	for (int x = pos; x < N; x |= x + 1) bit[x] += val;
}
int bitSum(int pos) {
	int ret = 0;
	for (int x = pos - 1; x >= 0; x = (x & (x + 1)) - 1) ret += bit[x];
	return ret;
}

int main() {
	
	
	for (; ~scanf("%d%d", &N, &P); ) {
		G = vector<vint>(N);
		for (int i = 0; i < N; ++i) {
			const int u = in() - 1;
			const int v = in() - 1;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		for (int u = 0; u < N; ++u) {
			deg[u] = G[u].size();
		}
// cout<<"deg : ";pv(deg,deg+N);
		memset(bit, 0, sizeof(bit));
		for (int u = 0; u < N; ++u) {
			bitAdd(deg[u], +1);
		}
		Int ans = 0;
		for (int u = 0; u < N; ++u) {
			bitAdd(deg[u], -1);
			for (int j = 0; j < deg[u]; ++j) {
				const int v = G[u][j];
				bitAdd(deg[v], -1);
				--deg[v];
				bitAdd(deg[v], +1);
			}
			ans += N - 1 - bitSum(max(P - deg[u], 0));
			bitAdd(deg[u], +1);
			for (int j = 0; j < deg[u]; ++j) {
				const int v = G[u][j];
				bitAdd(deg[v], -1);
				++deg[v];
				bitAdd(deg[v], +1);
			}
		}
		ans /= 2;
		cout << ans << endl;
	}
	
	return 0;
}
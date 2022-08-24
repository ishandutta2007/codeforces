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

#define MAX 400010

int N;
int m, ptr[MAX], next[MAX], zu[MAX];
Int V[MAX];
Int dpP[MAX], dpM[MAX];

void solve(int u, int p) {
	int i, v;
	for (i = ptr[u]; ~i; i = next[i]) {
		v = zu[i];
		if (v == p) continue;
		solve(v, u);
	}
	Int x = V[u];
	dpP[u] = 0;
	dpM[u] = 0;
	for (i = ptr[u]; ~i; i = next[i]) {
		v = zu[i];
		if (v == p) continue;
		chmax(dpP[u], dpP[v]);
		chmax(dpM[u], dpM[v]);
	}
	x += dpP[u];
	x -= dpM[u];
	if (x < 0) dpP[u] += -x;
	if (x > 0) dpM[u] += +x;
// cout<<u<<" : "<<dpP[u]<<" "<<dpM[u]<<endl;
}

int main() {
	int i, u, v;
	
	for (; ~scanf("%d", &N); ) {
		m = 0;
		memset(ptr, ~0, N << 2);
		for (i = 0; i < N - 1; ++i) {
			u = in() - 1;
			v = in() - 1;
			next[m] = ptr[u]; ptr[u] = m; zu[m] = v; ++m;
			next[m] = ptr[v]; ptr[v] = m; zu[m] = u; ++m;
		}
		for (u = 0; u < N; ++u) {
			V[u] = in();
		}
		solve(0, -1);
		Int ans = dpP[0] + dpM[0];
		cout << ans << endl;
	}
	
	return 0;
}
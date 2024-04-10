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

const Int INF = 1001001001001001001LL;

int N, U, R;
int A[110], B[110], P[110];
Int K[110];
int a[110][110];
Int ans;

void dfs(int u, bool flg) {
	int i;
	if ((U - u) % 2 == 0) {
		Int tmp = 0;
		for (i = 0; i < N; ++i) {
			tmp += a[u][i] * K[i];
		}
		chmax(ans, tmp);
	}
	if (u == U) {
		return;
	}
	if (!flg) {
		for (i = 0; i < N; ++i) {
			a[u + 1][i] = a[u][i] ^ B[i];
		}
		dfs(u + 1, 1);
	}
	{
		for (i = 0; i < N; ++i) {
			a[u + 1][i] = a[u][P[i]] + R;
		}
		dfs(u + 1, 0);
	}
}

int main() {
	int i;
	
	for (; ~scanf("%d%d%d", &N, &U, &R); ) {
		for (i = 0; i < N; ++i) A[i] = in();
		for (i = 0; i < N; ++i) B[i] = in();
		for (i = 0; i < N; ++i) K[i] = in();
		for (i = 0; i < N; ++i) P[i] = in() - 1;
		for (i = 0; i < N; ++i) {
			a[0][i] = A[i];
		}
		ans = -INF;
		dfs(0, 0);
		cout << ans << endl;
	}
	
	return 0;
}
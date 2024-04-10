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

#define MAXN 4010
const int T = 86400 + 1;

int N, K;
int A[MAXN], D[MAXN];
int dp[MAXN][MAXN];

int main() {
	int i, k;
	
	for (; ~scanf("%d%d", &N, &K); ) {
		for (i = 0; i < N; ++i) {
			A[i] = in();
			D[i] = in();
		}
		A[N] = T;
		memset(dp, 0x3f, sizeof(dp));
		for (k = 0; k <= K; ++k) {
			dp[0][k] = 1;
		}
		for (i = 0; i < N; ++i) {
			for (k = 0; k <= K; ++k) {
				chmin(dp[i + 1][k], max(dp[i][k], A[i]) + D[i]);
				chmin(dp[i + 1][k + 1], dp[i][k]);
			}
		}
		int ans = 0;
		for (i = 0; i <= N; ++i) {
			chmax(ans, A[i] - dp[i][K]);
		}
		printf("%d\n", ans);
	}
	
	return 0;
}
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

int N, M;
int P[1010];
int A[1010], B[1010];
double dp[1010][1010];

int main() {
	int i, x, y;
	
	for (; ~scanf("%d%d", &N, &M); ) {
		for (x = 0; x < N; ++x) {
			P[x] = in() - 1;
		}
		for (i = 0; i < M; ++i) {
			A[i] = in() - 1;
			B[i] = in() - 1;
		}
		for (x = 0; x < N; ++x) for (y = 0; y < N; ++y) {
			dp[x][y] = (P[x] > P[y]) ? 1.0 : 0.0;
		}
		for (i = 0; i < M; ++i) {
			for (x = 0; x < N; ++x) if (x != A[i] && x != B[i]) {
				dp[x][A[i]] = dp[x][B[i]] = (dp[x][A[i]] + dp[x][B[i]]) / 2.0;
				dp[A[i]][x] = dp[B[i]][x] = (dp[A[i]][x] + dp[B[i]][x]) / 2.0;
			}
			dp[A[i]][B[i]] = dp[B[i]][A[i]] = (dp[A[i]][B[i]] + dp[B[i]][A[i]]) / 2.0;
		}
		double ans = 0.0;
		for (x = 0; x < N; ++x) for (y = x + 1; y < N; ++y) {
			ans += dp[x][y];
		}
		printf("%.10f\n", ans);
	}
	
	return 0;
}
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

const Int MO = 1000000007;

int N, K;
int A[2010];
Int dp[2010][2050];

int main() {
	
	
	for (; ~scanf("%d%d", &N, &K); ) {
		for (int i = 0; i < N; ++i) {
			A[i] = in();
		}
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		for (int i = 0; i < N; ++i) for (int j = 0; j < 1 << K; ++j) {
			for (const int a : { 2, 4 }) {
				if (A[i] == a || A[i] == 0) {
					int jj = j;
					if (jj & (a - 1)) {
						jj = 0;
					}
					jj += a;
					if (jj < 1 << K) {
						(dp[i + 1][jj] += dp[i][j]) %= MO;
					}
				}
			}
		}
		Int ans = 1;
		for (int i = 0; i < N; ++i) {
			if (A[i] == 0) {
				(ans *= 2) %= MO;
			}
		}
		for (int j = 0; j < 1 << K; ++j) {
			(ans -= dp[N][j]) %= MO;
		}
		ans = (ans % MO + MO) % MO;
		cout << ans << endl;
	}
	
	return 0;
}
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

const Int MO = 7340033;

const int M = 35;
const int K = 1005;
Int dp[40][1010];
Int DP[5][1010];

int main() {
	int m, k, l;
	int i;
	int n;
	
	dp[0][0] = 1;
	for (m = 1; m < M; ++m) {
		memset(DP, 0, sizeof(DP));
		DP[0][0] = 1;
		for (i = 0; i < 4; ++i) {
			for (k = 0; k < K; ++k) for (l = 0; k + l < K; ++l) {
				(DP[i + 1][k + l] += DP[i][k] * dp[m - 1][l]) %= MO;
			}
		}
		dp[m][0] = 1;
		for (k = 1; k < K; ++k) {
			dp[m][k] = DP[4][k - 1];
		}
	}
// for(m=0;m<10;++m)pv(dp[m],dp[m]+10);
	
	for (int TC = in(); TC--; ) {
		n = in();
		k = in();
		m = 0;
		for (; n > 1 && n % 2 != 0; n /= 2) {
			++m;
		}
		cout << dp[m][k] << endl;
	}
	
	return 0;
}
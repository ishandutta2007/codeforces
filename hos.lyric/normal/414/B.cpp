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

const int MO = 1000000007;
inline void pl(int &t, const int f) {
	if ((t += f) >= MO) {
		t -= MO;
	}
}

const int LIM = 2005;

int dp[2010][2010];

int main() {
	int i, j, k;
	
	dp[0][1] = 1;
	for (i = 0; i < LIM; ++i) {
		for (j = 1; j < LIM; ++j) {
			for (k = j; k < LIM; k += j) {
				pl(dp[i + 1][k], dp[i][j]);
			}
		}
	}
	
	int N, K;
	for (; ~scanf("%d%d", &N, &K); ) {
		int ans = 0;
		for (j = 1; j <= N; ++j) {
			pl(ans, dp[K][j]);
		}
		printf("%d\n", ans);
	}
	
	return 0;
}
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

const int MO = 1000000007;
void pl(int &t, const int f) {
	if ((t += f) >= MO) {
		t -= MO;
	}
}

const int LIM = 5005;
const int ZERO = 5010;

int N;
int A[1010];

int dp[1010][10020][2];

int main() {
	int i;
	int x, xx, s, t;
	
	for (; ~scanf("%d", &N); ) {
		for (i = 0; i < N; ++i) {
			A[i] = in();
		}
		memset(dp, 0, sizeof(dp));
		dp[0][ZERO][0] = 1;
		for (i = 0; i < N; ++i) {
			for (x = -LIM; x <= +LIM; ++x) for (s = 0; s < 2; ++s) {
				if (s == 0) {
					pl(dp[i + 1][ZERO + x][s], dp[i][ZERO + x][s]);
				}
				for (t = 0; t < 2; ++t) {
					xx = (t == 0) ? (x + A[i]) : (x - A[i]);
					if (-LIM <= xx && xx <= +LIM) {
						pl(dp[i + 1][ZERO + xx][1], dp[i][ZERO + x][s]);
					}
				}
			}
		}
		int ans = 0;
		for (i = 0; i <= N; ++i) {
			pl(ans, dp[i][ZERO][1]);
		}
		printf("%d\n", ans);
	}
	
	return 0;
}
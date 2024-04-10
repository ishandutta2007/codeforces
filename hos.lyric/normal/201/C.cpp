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

const int BASE[] = { 0, 2, 1, 2, 0 };

int N;
Int A[100010];
Int dp[100010][10];

int main() {
	
	
	for (; ~scanf("%d", &N); ) {
		--N;
		for (int i = 0; i < N; ++i) {
			A[i] = in();
		}
		memset(dp, 0xc0, sizeof(dp));
		dp[0][0] = 0;
		for (int i = 0; i <= N; ++i) for (int j = 0; j < 5; ++j) if (dp[i][j] >= 0) {
// cout<<i<<" "<<j<<" : "<<dp[i][j]<<endl;
			for (int jj = j; jj < 5; ++jj) {
				if (A[i] >= BASE[jj]) {
					chmax(dp[i + 1][jj], dp[i][j] + ((BASE[jj] > 0) ? (BASE[jj] + (A[i] - BASE[jj]) / 2 * 2) : 0));
				}
			}
		}
		Int ans = 0;
		for (int j = 0; j < 5; ++j) {
			chmax(ans, dp[N][j]);
		}
		cout << ans << endl;
	}
	
	return 0;
}
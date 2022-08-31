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

const int LIM = 45;
Int dp[50][50];

void prepare() {
	int i, j;
	dp[0][0] = 1;
	for (i = 1; i < LIM; ++i) {
		dp[i][0] = 1;
		for (j = 1; j < LIM; ++j) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}
}

Int N, T;
int X;

int main() {
	int i;
	
	prepare();
	
	for (; cin >> N >> T; ) {
		if (T & (T - 1)) {
			cout << 0 << endl;
			continue;
		}
		X = __builtin_ctzll(T);
// cout<<"X = "<<X<<endl;
		Int ans = 0;
		Int n = N;
		int x = X;
		for (i = 1; ; ++i) {
			if (n < 1LL << i) {
				break;
			}
			n -= 1LL << i;
			ans += dp[i][x];
		}
		for (; --i >= 0 && x >= 0; ) {
			if (n >= 1LL << i) {
				ans += dp[i][x];
				n -= 1LL << i;
				--x;
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}
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
#include <deque>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef unsigned uint;
typedef long long Int;
typedef vector<int> vint;
typedef pair<int,int> pint;
#define mp make_pair

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T &t, const T &f) { if (t > f) t = f; }
template<typename T> void chmax(T &t, const T &f) { if (t < f) t = f; }
int in() { int x; scanf("%d", &x); return x; }

int X, K;
double P;
double dp[210][250][250];

int main() {
	
	
	for (; ~scanf("%d%d", &X, &K); ) {
		P = in() / 100.0;
		memset(dp, 0, sizeof(dp));
		dp[0][0][0] = 1.0;
		double ans = 0.0;
		for (int k = 0; k < K; ++k) for (int p = 0; p < 35 + K; ++p) for (int s = 0; s < 35 + K; ++s) {
			if (s % 2 != 0) {
// if(dp[k][p][s]>0)cout<<" give up "<<k<<" "<<p<<" "<<s<<" : "<<dp[k][p][s]<<endl;
				ans += (dp[k][p][s] * P) * p;
			} else {
				dp[k + 1][p + 1][s >> 1] += dp[k][p][s] * P;
			}
			dp[k + 1][p][s + 1] += dp[k][p][s] * (1.0 - P);
		}
		for (int p = 0; p < 35 + K; ++p) for (int s = 0; s < 35 + K; ++s) {
			ans += dp[K][p][s] * (p + __builtin_ctz(X + s));
		}
		printf("%.10f\n", ans);
	}
	
	return 0;
}
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

const int INF = 1001001001;

int N, K;
int L[110];
string S[110];

int dp[110][110][110];

void solve(int a, int b, int x0) {
	int *DP = dp[a][b];
	int x;
	int i, j;
	int k, kk;
	for (x = x0; x < L[a]; ++x) {
		for (i = a; i < b; ++i) if (!(x < L[i] && S[a][x] == S[i][x])) break;
		if (i < b) break;
	}
	for (k = 0; k <= b - a; ++k) {
		DP[k] = -INF;
	}
	DP[0] = 0;
	for (i = a; i < b; i = j) {
		for (j = i; j < b && S[i][x] == S[j][x]; ++j);
		if (i == a && j == b) {
			for (k = 0; k <= b - a; ++k) {
				DP[k] = 0;
			}
			break;
		}
		solve(i, j, x);
		for (k = b - a; k >= 0; --k) {
			for (kk = 0; kk <= j - i && kk <= k; ++kk) {
				chmax(DP[k], DP[k - kk] + dp[i][j][kk]);
			}
		}
	}
	for (k = 0; k <= b - a; ++k) {
		DP[k] += (x - x0) * (k * (k - 1) / 2);
	}
// cout<<a<<" "<<b<<" "<<x0<<" : ";pv(DP,DP+b-a+1);
}

int main() {
	int i;
	char buf[510];
	
	for (; ~scanf("%d%d", &N, &K); ) {
		for (i = 0; i < N; ++i) {
			scanf("%s", buf);
			S[i] = buf;
		}
		sort(S, S + N);
		for (i = 0; i < N; ++i) {
			L[i] = S[i].size();
			S[i] += "!";
		}
		solve(0, N, 0);
		printf("%d\n", dp[0][N][K]);
	}
	
	return 0;
}
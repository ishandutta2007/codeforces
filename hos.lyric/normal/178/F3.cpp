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

int lcp(const string &a, const string &b) {
	int m = a.size(), n = b.size();
	int i;
	for (i = 0; i < m && i < n; ++i) if (a[i] != b[i]) break;
	return i;
}

int N, K;
string S[2010];
int D[2010];

int poolPos;
int pool[4010][2010];

int *solve(int a, int b, int d) {
	int *dp = pool[poolPos++];
	if (a == b) {
		dp[0] = 0;
		dp[1] = 0;
	} else {
		int i, im = -1;
		pint sho = mp(INF, INF);
		for (i = a; i < b; ++i) {
			pint tmp = mp(D[i], max(i - a, b - (i + 1)));
			if (sho > tmp) {
				sho = tmp;
				im = i;
			}
		}
		int *dpL = solve(a, im, D[im]);
		int *dpR = solve(im + 1, b, D[im]);
		int k, kL, kR;
		for (k = 0; k <= b - a + 1 && k <= K; ++k) {
			dp[k] = -INF;
		}
		for (kL = 0; kL <= im - a + 1 && kL <= K; ++kL) {
			for (kR = 0; kR <= b - (im + 1) + 1 && kL + kR <= K; ++kR) {
				chmax(dp[kL + kR], dpL[kL] + dpR[kR]);
			}
		}
		for (k = 0; k <= b - a + 1 && k <= K; ++k) {
			dp[k] += (D[im] - d) * (k * (k - 1) / 2);
		}
	}
// cout<<a<<" "<<b<<" "<<d<<" : ";pv(dp,dp+min(b-a+1,K)+1);
	return dp;
}

char buf[1010];

int main() {
	int i;
	
	for (; ~scanf("%d%d", &N, &K); ) {
		for (i = 0; i < N; ++i) {
			scanf("%s", buf);
			S[i] = buf;
		}
		sort(S, S + N);
		for (i = 0; i < N - 1; ++i) {
			D[i] = lcp(S[i], S[i + 1]);
		}
// cout<<"D : ";pv(D,D+N-1);
		poolPos = 0;
		int *res = solve(0, N - 1, 0);
		printf("%d\n", res[K]);
	}
	
	return 0;
}
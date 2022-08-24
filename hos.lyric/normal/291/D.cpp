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

int N, K;
int C[30][10010];

int as[30][10010];

void validate() {
	int k, i;
	for (i = 0; i < N; ++i) {
		as[0][i] = (i != 0) ? 1 : 0;
	}
	for (k = 0; k < K; ++k) {
		for (i = 0; i < N; ++i) {
			as[k + 1][i] = as[k][i] + as[k][C[k][i]];
		}
	}
	cout << "as[K] : "; pv(as[K], as[K] + N);
}

int main() {
	int k, i;
	
	for (; ~scanf("%d%d", &N, &K); ) {
		for (k = 0; k < K; ++k) {
			C[k][0] = 0;
			for (i = 1; i < N; ++i) {
				C[k][i] = ((i - 1) & 1 << k) ? (1 << k) : 0;
			}
		}
// validate();
		for (k = 0; k < K; ++k) {
			for (i = N; i--; ) {
				printf("%d", N - C[k][i]);
				if (i) printf(" ");
			}
			puts("");
		}
	}
	
	return 0;
}
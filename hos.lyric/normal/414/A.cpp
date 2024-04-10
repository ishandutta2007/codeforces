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

int N, K;
int A[100010];

int M;

int main() {
	int i;
	
	for (; ~scanf("%d%d", &N, &K); ) {
		M = N / 2;
		if (K < M) {
			puts("-1");
			continue;
		}
		if (N == 1) {
			if (K > 0) {
				puts("-1");
			} else {
				puts("1");
			}
			continue;
		}
		int q = K / M;
		int r = K % M;
		for (i = 0; i < M; ++i) {
			int g = (i < M - r) ? q : (q + 1);
			A[i * 2 + 0] = (i * 2 + 1) * g;
			A[i * 2 + 1] = (i * 2 + 2) * g;
		}
		if (N % 2 != 0) {
			A[N - 1] = 999999999;
		}
		for (i = 0; i < N; ++i) {
			if (i) printf(" ");
			printf("%d", A[i]);
		}
		puts("");
	}
	
	return 0;
}
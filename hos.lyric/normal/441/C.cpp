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

int M, N, K;
int xs[100010], ys[100010];

int main() {
	
	
	for (; ~scanf("%d%d%d", &M, &N, &K); ) {
		for (int x = 0; x < M; ++x) for (int y = 0; y < N; ++y) {
			xs[x * N + y] = x;
			ys[x * N + y] = y;
		}
		for (int x = 0; x < M; ++x) if (x % 2 != 0) {
			reverse(ys + x * N, ys + (x + 1) * N);
		}
		for (int k = 0; k < K; ++k) {
			const int len = (k < K - 1) ? 2 : (M * N - (K - 1) * 2);
			printf("%d", len);
			for (int i = k * 2; i < k * 2 + len; ++i) {
				printf(" %d %d", xs[i] + 1, ys[i] + 1);
			}
			puts("");
		}
	}
	
	return 0;
}
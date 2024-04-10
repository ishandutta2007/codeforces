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
char A[2010][2010];

int ans[2010];

int main() {
	
	
	for (; ~scanf("%d%d%d", &M, &N, &K); ) {
		for (int x = 0; x < M; ++x) {
			scanf("%s", A[x]);
		}
		fill_n(ans, N, 0);
		for (int x = 0; x < M; ++x) for (int y = 0; y < N; ++y) {
			switch (A[x][y]) {
				case 'L': {
					//	time x
					const int yHit = y - x;
					if (0 <= yHit && yHit < N) {
						++ans[yHit];
					}
				} break;
				case 'R': {
					//	time x
					const int yHit = y + x;
					if (0 <= yHit && yHit < N) {
						++ans[yHit];
					}
				} break;
				case 'U': {
					//	time t s.t. t = x - t
					if (x % 2 == 0) {
						++ans[y];
					}
				} break;
				case 'D': {
					
				} break;
				case '.': {
					
				} break;
				default: assert(false);
			}
		}
		for (int y = 0; y < N; ++y) {
			if (y) printf(" ");
			printf("%d", ans[y]);
		}
		puts("");
	}
	
	return 0;
}
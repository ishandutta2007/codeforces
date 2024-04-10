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



int N;
char A[110][10];
int is[110][110];

int main() {
	
	
	for (; ~scanf("%d", &N); ) {
		for (int i = 0; i < N; ++i) {
			scanf("%s", A[i]);
		}
		memset(is, 0, sizeof(is));
		for (int i = 0; i < N; ++i) {
			++is[string("RGBYW").find(A[i][0])][string("12345").find(A[i][1])];
		}
		int ans = 5 + 5;
		for (int p = 0; p < 1 << 5; ++p) for (int q = 0; q < 1 << 5; ++q) {
			int worst = 0;
			for (int x = 0; x < 5; ++x) if (p & 1 << x) {
				int cnt = 0;
				for (int y = 0; y < 5; ++y) if (!(q & 1 << y)) {
					if (is[x][y]) {
						++cnt;
					}
				}
				chmax(worst, cnt);
			}
			for (int y = 0; y < 5; ++y) if (q & 1 << y) {
				int cnt = 0;
				for (int x = 0; x < 5; ++x) if (!(p & 1 << x)) {
					if (is[x][y]) {
						++cnt;
					}
				}
				chmax(worst, cnt);
			}
			{
				int cnt = 0;
				for (int x = 0; x < 5; ++x) if (!(p & 1 << x)) for (int y = 0; y < 5; ++y) if (!(q & 1 << y)) {
					if (is[x][y]) {
						++cnt;
					}
				}
				chmax(worst, cnt);
			}
			if (worst <= 1) {
				chmin(ans, __builtin_popcount(p) + __builtin_popcount(q));
			}
		}
		printf("%d\n", ans);
	}
	
	return 0;
}
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

int N, M;
int B[110];
int ans[110];

int main() {
	int i, j;
	
	for (; ~scanf("%d%d", &N, &M); ) {
		for (i = 0; i < M; ++i) {
			B[i] = in();
		}
		memset(ans, 0, sizeof(ans));
		for (i = 0; i < M; ++i) {
			for (j = 1; j <= N; ++j) {
				if (!(j < B[i])) {
					if (!ans[j]) {
						ans[j] = B[i];
					}
				}
			}
		}
		for (j = 1; j <= N; ++j) {
			if (j > 1) printf(" ");
			printf("%d", ans[j]);
		}
		puts("");
	}
	
	return 0;
}
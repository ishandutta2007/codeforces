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

int N, V;
int K[110];
int S[110][110];

int ansLen;
int ans[110];

int main() {
	
	
	for (; ~scanf("%d%d", &N, &V); ) {
		for (int i = 1; i <= N; ++i) {
			K[i] = in();
			for (int j = 1; j <= K[i]; ++j) {
				S[i][j] = in();
			}
		}
		ansLen = 0;
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= K[i]; ++j) {
				if (V > S[i][j]) {
					ans[ansLen++] = i;
					break;
				}
			}
		}
		printf("%d\n", ansLen);
		for (int h = 0; h < ansLen; ++h) {
			if (h) printf(" ");
			printf("%d", ans[h]);
		}
		puts("");
	}
	
	return 0;
}
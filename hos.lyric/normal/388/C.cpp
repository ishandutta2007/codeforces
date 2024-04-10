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

int N;
int S[110];
int C[110][110];

int midsLen;
int mids[110];

int main() {
	int i, j;
	
	for (; ~scanf("%d", &N); ) {
		for (i = 0; i < N; ++i) {
			S[i] = in();
			for (j = 0; j < S[i]; ++j) {
				C[i][j] = in();
			}
		}
		midsLen = 0;
		int ansL = 0, ansR = 0;
		for (i = 0; i < N; ++i) {
			for (j = 0; j < S[i] / 2; ++j) {
				ansL += C[i][j];
			}
			if (S[i] % 2 != 0) {
				mids[midsLen++] = C[i][S[i] / 2];
			}
			for (j = S[i] - S[i] / 2; j < S[i]; ++j) {
				ansR += C[i][j];
			}
		}
		sort(mids, mids + midsLen, greater<int>());
		for (i = 0; i < N; ++i) {
			((i % 2 == 0) ? ansL : ansR) += mids[i];
		}
		printf("%d %d\n", ansL, ansR);
	}
	
	return 0;
}
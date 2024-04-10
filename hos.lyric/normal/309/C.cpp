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

const int L = 30;
int N, M;
int A[1000010], B[1000010];

int cnt[110];

bool check(int m) {
	int i, j, l;
	memset(cnt, 0, L * 4);
	for (j = 0; j < m; ++j) {
		++cnt[B[j]];
	}
	for (i = N; i--; ) {
		int a = A[i];
		for (l = L; l--; ) {
			int tmp = min(cnt[l], a >> l);
			cnt[l] -= tmp;
			a -= tmp << l;
		}
	}
	for (l = 0; l < L; ++l) {
		if (cnt[l] > 0) {
			return 0;
		}
	}
	return 1;
}

int main() {
	int i, j;
	
	for (; ~scanf("%d%d", &N, &M); ) {
		for (i = 0; i < N; ++i) {
			A[i] = in();
		}
		for (j = 0; j < M; ++j) {
			B[j] = in();
		}
		sort(A, A + N);
		sort(B, B + M);
		int lo = 0, ho = M + 1;
		for (; lo + 1 < ho; ) {
			int mo = (lo + ho) / 2;
			(check(mo) ? lo : ho) = mo;
		}
		printf("%d\n", lo);
	}
	
	return 0;
}
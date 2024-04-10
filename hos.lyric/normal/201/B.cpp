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

const Int INF = 1001001001001001001LL;

pair<Int,int> solve(int n, Int a[]) {
	Int ret = INF;
	int im = -1;
	for (int i = 0; i <= n; ++i) {
		Int tmp = 0;
		for (int j = 0; j < n; ++j) {
			const int diff = (4 * i) - (4 * j + 2);
			tmp += a[j] * diff * diff;
		}
		if (ret > tmp) {
			ret = tmp;
			im = i;
		}
	}
	return mp(ret, im);
}

int M, N;
Int C[1010][1010];

Int A[1010], B[1010];

int main() {
	
	
	for (; ~scanf("%d%d", &M, &N); ) {
		for (int x = 0; x < M; ++x) for (int y = 0; y < N; ++y) {
			C[x][y] = in();
		}
		memset(A, 0, sizeof(A));
		memset(B, 0, sizeof(B));
		for (int x = 0; x < M; ++x) for (int y = 0; y < N; ++y) {
			A[x] += C[x][y];
			B[y] += C[x][y];
		}
		const pair<Int,int> resX = solve(M, A);
		const pair<Int,int> resY = solve(N, B);
		cout << (resX.first + resY.first) << endl;
		cout << resX.second << " " << resY.second << endl;
	}
	
	return 0;
}
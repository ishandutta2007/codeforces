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
int A[110];

int now[110];

bool dfs(int i, int a, int dg, int lst) {
	if (i == N) {
		return true;
	}
	if (a == 1) {
		if (dg != 1) {
			++now[A[i]];
			return dfs(i + 1, A[i + 1], 0, N);
		}
	} else {
		for (int c = min(a - 1, lst); c >= 1; --c) if (now[c]) {
			--now[c];
			if (dfs(i, a - c, dg + 1, c)) {
				return true;
			}
			++now[c];
		}
	}
	return false;
}

bool solve() {
	if (A[N - 1] != N) {
		return false;
	}
	if (count(A, A + N, 2) != 0) {
		return false;
	}
	for (int i = 0; i < N; ++i) {
		if (A[i] > i + 1) {
			return false;
		}
	}
	A[N] = 0;
	fill_n(now, N + 1, 0);
	return dfs(0, A[0], 0, N);
}

int main() {
	
	
	for (; ~scanf("%d", &N); ) {
		for (int i = 0; i < N; ++i) {
			A[i] = in();
		}
		sort(A, A + N);
		puts(solve() ? "YES" : "NO");
	}
	
	return 0;
}
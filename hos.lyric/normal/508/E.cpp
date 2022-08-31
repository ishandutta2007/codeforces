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
#include <cstdint>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef long long Int;
typedef vector<int> vint;
typedef pair<int, int> pint;
#define mp make_pair

template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template <typename T> void chmin(T &t, const T &f) { if (t > f) t = f; }
template <typename T> void chmax(T &t, const T &f) { if (t < f) t = f; }
int in() { int x; scanf("%d", &x); return x; }

int N;
int A[610], B[610];

bool mem[610][610];
bool dp[610][610];

int ansLen;
char ans[1210];

bool calc(int a, int b) {
	if (a >= b) {
		return true;
	}
	if (!mem[a][b]) {
		bool ret = false;
		for (int c = a + 1; c <= b; ++c) {
			const int dist = (c - a) * 2 - 1;
			if (A[a] <= dist && dist <= B[a]) {
				if (calc(a + 1, c) && calc(c, b)) {
					ret = true;
					break;
				}
			}
		}
		mem[a][b] = true;
		dp[a][b] = ret;
	}
	return dp[a][b];
}

void recover(int a, int b) {
	if (a >= b) {
		return;
	}
	{
		for (int c = a + 1; c <= b; ++c) {
			const int dist = (c - a) * 2 - 1;
			if (A[a] <= dist && dist <= B[a]) {
				if (calc(a + 1, c) && calc(c, b)) {
					ans[ansLen++] = '(';
					recover(a + 1, c);
					ans[ansLen++] = ')';
					recover(c, b);
					return;
				}
			}
		}
	}
}

int main() {
	
	
	for (; ~scanf("%d", &N); ) {
		for (int i = 0; i < N; ++i) {
			A[i] = in();
			B[i] = in();
		}
		for (int i = 0; i <= N; ++i) {
			fill(mem[i], mem[i] + N + 1, false);
		}
		const bool res = calc(0, N);
		if (res) {
			// puts("TODO");
			fill(ans, ans + N * 2, '?');
			ansLen = 0;
			recover(0, N);
			assert(ansLen == N * 2);
			for (int x = 0; x < N * 2; ++x) {
				assert(ans[x] != '?');
			}
			ans[N * 2] = '\0';
			puts(ans);
		} else {
			puts("IMPOSSIBLE");
		}
	}
	
	return 0;
}
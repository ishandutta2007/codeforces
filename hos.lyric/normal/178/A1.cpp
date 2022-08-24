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

void out(Int x) {
	if (x >= 10) out(x / 10);
	putchar('0' + x % 10);
}

int N;
Int A[100010];
Int dp[100010];

int main() {
	int i, j;
	
	for (; ~scanf("%d", &N); ) {
		for (i = 0; i < N; ++i) {
			A[i] = in();
		}
		Int ans = 0;
		for (i = 0; i < N - 1; ++i) {
			for (j = N - 1 - i; j & j - 1; j &= j - 1);
			ans += A[i];
			A[i + j] += A[i];
			out(ans);
			puts("");
		}
	}
	
	return 0;
}
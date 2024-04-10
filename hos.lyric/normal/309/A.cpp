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

int N;
Int L, T;
Int A[2000010];

int main() {
	int i, j;
	
	for (; ~scanf("%d", &N); ) {
		L = in();
		T = in();
		for (i = 0; i < N; ++i) {
			A[i] = in();
		}
		sort(A, A + N);
		for (i = N; i <= N * 2; ++i) {
			A[i] = A[i - N] + L;
		}
		Int q = (T * 2) / L;
		Int r = (T * 2) % L;
		Int cnt = 0;
		for (j = 0, i = 0; i < N; ++i) {
			for (; A[j] - A[i] <= r; ++j);
			cnt += j - i - 1;
		}
		double ans = 0;
		ans += 0.25 * ((double)N * (N - 1) * q + cnt);
		printf("%.10f\n", ans);
	}
	
	return 0;
}
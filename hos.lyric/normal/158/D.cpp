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

const int INF = 1001001001;

int N;
int A[20010];

int main() {
	int i, d, e;
	
	for (; ~scanf("%d", &N); ) {
		for (i = 0; i < N; ++i) {
			A[i] = in();
		}
		int ans = -INF;
		for (d = 1; d <= N; ++d) if (N % d == 0 && N / d >= 3) {
			for (e = 0; e < d; ++e) {
				int tmp = 0;
				for (i = e; i < N; i += d) {
					tmp += A[i];
				}
				chmax(ans, tmp);
			}
		}
		printf("%d\n", ans);
	}
	
	return 0;
}
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
Int K;
Int A[100010];
bool used[100010];

int main() {
	int i;
	
	for (; ~scanf("%d", &N); ) {
		K = in();
		for (i = 0; i < N; ++i) {
			A[i] = in();
		}
		sort(A, A + N);
		if (K == 1) {
			printf("%d\n", N);
			continue;
		}
		memset(used, 0, N);
		int ans = 0;
		for (i = 0; i < N; ++i) {
			if (!used[i]) {
				++ans;
				int j = lower_bound(A, A + N, A[i] * K) - A;
				if (j < N && A[j] == A[i] * K) {
					used[j] = 1;
				}
			}
		}
		printf("%d\n", ans);
	}
	
	return 0;
}
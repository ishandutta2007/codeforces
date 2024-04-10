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

#define MAX 100010

int M;
int Q[MAX];
int N;
int A[MAX];

int main() {
	int i, j;
	
	for (; ~scanf("%d", &M); ) {
		for (i = 0; i < M; ++i) {
			Q[i] = in();
		}
		N = in();
		for (j = 0; j < N; ++j) {
			A[j] = in();
		}
		sort(Q, Q + M);
		sort(A, A + N, greater<int>());
		int ans = 0;
		for (j = 0; j < N; ++j) if (j % (Q[0] + 2) < Q[0]) {
			ans += A[j];
		}
		printf("%d\n", ans);
	}
	
	return 0;
}
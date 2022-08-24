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
#define MAX 1000010

int M, N;
int A[MAX], B[MAX];
int invB[MAX];

Int D[MAX * 2];
Int DSum[MAX * 2];

int main() {
	int i, j, x;
	
	for (; ~scanf("%d%d", &M, &N); ) {
		for (i = 0; i < M; ++i) {
			A[i] = in();
		}
		for (x = 0; x < N; ++x) {
			B[x] = in();
		}
		memset(invB, ~0, sizeof(invB));
		for (x = 0; x < N; ++x) {
			invB[B[x]] = x;
		}
		for (i = 0; i < M * 2; ++i) {
			int x0 = invB[A[ i      % M]];
			int x1 = invB[A[(i + 1) % M]];
			if (~x0 && ~x1) {
				for (D[i] = x1 - x0; D[i] <= 0; D[i] += N);
			} else {
				D[i] = INF;
			}
		}
// cout<<"D : ";pv(D,D+M*2);
		for (i = 0; i < M * 2; ++i) {
			DSum[i + 1] = DSum[i] + D[i];
		}
		int ans = 0;
		for (j = 0, i = 0; i < M; ++i) {
			for (; j <= i + M && DSum[j] - DSum[i] < N; ++j);
// cout<<"i = "<<i<<", j = "<<j<<endl;
			if (~invB[A[i % M]]) {
				chmax(ans, j - i);
			}
		}
		printf("%d\n", ans);
	}
	
	return 0;
}
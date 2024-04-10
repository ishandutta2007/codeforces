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
pint P[100010];
int A[100010], B[100010];

int main() {
	
	
	for (; ~scanf("%d", &N); ) {
		for (int i = 0; i < N; ++i) {
			P[i].first = in();
			P[i].second = i;
		}
		sort(P, P + N);
		const int discard = (N + 2) / 3;
		for (int i = 0; i < N; ++i) {
			const int j = P[i].second;
			if (i < discard) {
				A[j] = i;
				B[j] = P[i].first - A[j];
			} else if (i < discard * 2) {
				B[j] = i;
				A[j] = P[i].first - B[j];
			} else {
				B[j] = N - 1 - i;
				A[j] = P[i].first - B[j];
			}
		}
		puts("YES");
		for (int j = 0; j < N; ++j) {
			if (j > 0) printf(" ");
			printf("%d", A[j]);
		}
		puts("");
		for (int j = 0; j < N; ++j) {
			if (j > 0) printf(" ");
			printf("%d", B[j]);
		}
		puts("");
	}
	
	return 0;
}
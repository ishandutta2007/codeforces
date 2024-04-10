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

#define MAX 200010

int N, M;
int A[MAX], B[MAX];
int deg[MAX];

bool isBus() {
	if (M != N - 1) return 0;
	int degMax = *max_element(deg, deg + N);
	if (degMax > 2) return 0;
	return 1;
}
bool isRing() {
	if (M != N) return 0;
	int degMax = *max_element(deg, deg + N);
	if (degMax > 2) return 0;
	return 1;
}
bool isStar() {
	if (M != N - 1) return 0;
	int degMax = *max_element(deg, deg + N);
	if (degMax != N - 1) return 0;
	return 1;
}

int main() {
	int i;
	
	for (; ~scanf("%d%d", &N, &M); ) {
		for (i = 0; i < M; ++i) {
			A[i] = in() - 1;
			B[i] = in() - 1;
		}
		memset(deg, 0, N << 2);
		for (i = 0; i < M; ++i) {
			++deg[A[i]];
			++deg[B[i]];
		}
		if (isBus()) {
			puts("bus topology");
		} else if (isRing()) {
			puts("ring topology");
		} else if (isStar()) {
			puts("star topology");
		} else {
			puts("unknown topology");
		}
	}
	
	return 0;
}
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
template<class T> void chmin(T &t, const T &f) { if (t > f) t = f; }
template<class T> void chmax(T &t, const T &f) { if (t < f) t = f; }
int in() { int x; scanf("%d", &x); return x; }

int N;
Int A, B;
Int X[100010];
Int ans[100010];

int main() {
	int i;
	
	for (; ~scanf("%d", &N); ) {
		A = in();
		B = in();
		for (i = 0; i < N; ++i) {
			X[i] = in();
		}
		for (i = 0; i < N; ++i) {
			Int money = X[i] * A / B;
			//	x * A / B >= money
			ans[i] = X[i] - (money * B + A - 1) / A;
		}
		for (i = 0; i < N; ++i) {
			if (i) printf(" ");
			printf("%d", (int)ans[i]);
		}
		puts("");
	}
	
	return 0;
}
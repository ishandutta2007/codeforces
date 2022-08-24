//	UOI 2011.04.12.

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

typedef long long Int;
typedef vector<int> vint;
typedef pair<int,int> pint;
#define mp make_pair

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t > f) t = f; }
int in() { int x; scanf("%d", &x); return x; }

int N;
Int X[100010], Y[100010];

Int solve(Int a[]) {
	int i;
	Int s1 = 0, s2 = 0;
	for (i = 0; i < N; ++i) {
		s1 += a[i];
		s2 += a[i] * a[i];
	}
	return s2 * (N - 1) - (s1 * s1 - s2);
}

int main() {
	int i;
	
	for (; ~scanf("%d", &N); ) {
		for (i = 0; i < N; ++i) {
			X[i] = in();
			Y[i] = in();
		}
		Int ans = 0;
		ans += solve(X);
		ans += solve(Y);
		cout << ans << endl;
	}
	
	
	return 0;
}
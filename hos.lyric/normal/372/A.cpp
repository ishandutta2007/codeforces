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
int S[500010];

bool check(int k) {
	int i;
	for (i = 0; i < k; ++i) {
		if (!(S[i] * 2 <= S[N - k + i])) {
			return 0;
		}
	}
	return 1;
}

int main() {
	int i;
	
	for (; ~scanf("%d", &N); ) {
		for (i = 0; i < N; ++i) {
			S[i] = in();
		}
		sort(S, S + N);
		int lo = 0, ho = N / 2 + 1;
		for (; lo + 1 < ho; ) {
			int mo = (lo + ho) / 2;
			(check(mo) ? lo : ho) = mo;
		}
		printf("%d\n", N - lo);
	}
	
	return 0;
}
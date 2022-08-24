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

Int N, M;

bool check(Int k) {
	//	N <= 2^^k
	if (k <= 30) {
		if (N > 1LL << k) {
			return false;
		}
	}
	Int comb = 1;
	Int n = N;
	Int ask = 0;
	for (int r = 0; n > 0; ++r) {
		Int tmp = min(comb, n);
		n -= tmp;
		ask += r * tmp;
		comb = comb * (k - r) / (1 + r);
	}
	return (ask <= M * k);
}

int main() {
	
	
	for (int TC = in(); TC--; ) {
		N = in();
		M = in();
		Int lo = -1, ho = N - 1;
		for (; lo + 1 < ho; ) {
			Int mo = (lo + ho) / 2;
			(check(mo) ? ho : lo) = mo;
		}
		cout << ho << endl;
	}
	
	return 0;
}
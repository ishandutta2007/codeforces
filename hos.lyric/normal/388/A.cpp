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
int X[110];

int asLen;
int as[110];

int main() {
	int i, j;
	
	for (; ~scanf("%d", &N); ) {
		for (i = 0; i < N; ++i) {
			X[i] = in();
		}
		sort(X, X + N);
		asLen = 0;
		for (i = 0; i < N; ++i) {
			sort(as, as + asLen, greater<int>());
			for (j = 0; j < asLen; ++j) {
				if (X[i] >= as[j]) {
					++as[j];
					break;
				}
			}
			if (j == asLen) {
				as[asLen++] = 1;
			}
		}
		printf("%d\n", asLen);
	}
	
	return 0;
}
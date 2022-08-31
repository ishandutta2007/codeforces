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

Int Abs(Int r) { return (r < 0) ? -r : r; }

int N, M;
Int A[100010];
Int B[100010];

bool check(Int limit) {
	int i, j = 0;
	for (i = 0; i < N; ++i) {
		int j0 = j;
		for (; j < M; ++j) {
			if (Abs(A[i] - B[j0]) + Abs(B[j0] - B[j ]) > limit && 
				Abs(A[i] - B[j ]) + Abs(B[j ] - B[j0]) > limit) {
				break;
			}
		}
	}
	return (j == M);
}

int main() {
	int i, j;
	
	for (; cin >> N >> M; ) {
		for (i = 0; i < N; ++i) {
			cin >> A[i];
		}
		for (j = 0; j < M; ++j) {
			cin >> B[j];
		}
		Int lo = -1, ho = 101001001001LL;
		for (; lo + 1 < ho; ) {
			Int mo = (lo + ho) / 2;
			(check(mo) ? ho : lo) = mo;
		}
		cout << ho << endl;
	}
	
	return 0;
}
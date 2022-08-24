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

const int LIM = 105;
Int bn[110][110];

int N, M, T;

int main() {
	int i, j;
	
	for (i = 0; i < LIM; ++i) {
		bn[i][0] = bn[i][i] = 1;
		for (j = 1; j < i; ++j) {
			bn[i][j] = bn[i - 1][j - 1] + bn[i - 1][j];
		}
	}
	
	int n, m;
	
	for (; ~scanf("%d%d%d", &N, &M, &T); ) {
		Int ans = 0;
		for (n = 4; n <= N; ++n) {
			m = T - n;
			if (1 <= m && m <= M) {
				ans += bn[N][n] * bn[M][m];
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}
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

int N, M;

int main() {
	int n;
	
	for (; ~scanf("%d%d", &N, &M); ) {
		int sho = +INF, dai = -INF;
		for (n = 0; n <= N && n <= M; ++n) {
			if (n == 0 && M - n > 0) continue;
			int tmp = n + (N - n) + (M - n);
			chmin(sho, tmp);
			chmax(dai, tmp);
		}
		if (sho > dai) {
			puts("Impossible");
		} else {
			printf("%d %d\n", sho, dai);
		}
	}
	
	return 0;
}
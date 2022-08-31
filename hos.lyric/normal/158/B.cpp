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

int solve(int a1, int a2, int a3, int a4) {
	int ret = 0;
	for (; a4 >= 1; ++ret) { a4 -= 1; }
	for (; a3 >= 1; ++ret) { a3 -= 1; a1 = max(a1 - 1, 0); }
	for (; a2 >= 2; ++ret) { a2 -= 2; }
	for (; a2 >= 1; ++ret) { a2 -= 1; a1 = max(a1 - 2, 0); }
	for (; a1 >= 1; ++ret) { a1 = max(a1 - 4, 0); }
	return ret;
}

int N;
int is[10];

int main() {
	int i;
	
	for (; ~scanf("%d", &N); ) {
		memset(is, 0, sizeof(is));
		for (i = 0; i < N; ++i) {
			++is[in()];
		}
		int res = solve(is[1], is[2], is[3], is[4]);
		printf("%d\n", res);
	}
	
	return 0;
}
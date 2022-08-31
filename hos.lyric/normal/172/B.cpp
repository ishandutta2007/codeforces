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

int A, B, M, R0;
int is[100010];

int main() {
	int i;
	
	for (; ~scanf("%d%d%d%d", &A, &B, &M, &R0); ) {
		memset(is, ~0, sizeof(is));
		int x = R0;
		for (i = 0; ; ++i) {
			if (~is[x]) {
				printf("%d\n", i - is[x]);
				break;
			}
			is[x] = i;
			x = (A * x + B) % M;
		}
	}
	
	return 0;
}
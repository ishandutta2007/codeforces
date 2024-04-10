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

Int N;

int dsLen;
Int ds[100010];

int main() {
	Int x, y, z;
	Int d;
	int i, j;
	
	for (; cin >> N; ) {
		if (N % 3 != 0) {
			puts("0");
			continue;
		}
		N /= 3;
		for (d = 1; d * d <= N; ++d) if (N % d == 0) {
			ds[dsLen++] = d;
		}
		int ans = 0;
		for (i = 0; i < dsLen; ++i) {
			x = ds[i];
			if (x * x * x > N) break;
			Int n = N / x;
			for (j = i; j < dsLen; ++j) {
				y = ds[j];
				if (y * y > n) break;
				if (n % y == 0) {
					z = n / y;
					if ((x + y + z) % 2 == 0 && x + y > z) {
						if (x == z) {
							ans += 1;
						} else if (x == y || y == z) {
							ans += 3;
						} else {
							ans += 6;
						}
					}
				}
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}
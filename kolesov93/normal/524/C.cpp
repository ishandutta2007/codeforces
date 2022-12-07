#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <set>
#include <deque>
#include <map>
#include <functional>
#include <numeric>
#include <sstream>
#include <complex>
#include <unordered_set>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

const int INF = 1e9;
int a[5555];
unordered_set<int> all;

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
	                       
	int n, k;
	scanf("%d%d", &n, &k);
	all.reserve(3*n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		all.insert(a[i]);
	}

	int q;
	scanf("%d", &q);
	while (q--) {
		int x;
		scanf("%d", &x);

		int ans = INF;
		for (int i = 0; i < n; ++i)
		for (int ii = 1; ii <= k; ++ii) {
			int c1 = a[i] * ii;
			if (c1 == x) {
				ans = min(ans, ii);
				continue;
			}

			for (int jj = 1; jj + ii <= k; ++jj) {
				int rest = x - c1;
				if (rest % jj) continue;
				if (all.count(rest / jj)) {
					ans = min(ans, ii + jj);
				}
			}
		}

		if (ans == INF)
			cout << -1 << "\n";
		else
			cout << ans << "\n";
	}
    
    return 0;
}
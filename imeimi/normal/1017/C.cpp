#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <functional>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	int v = n + 100, m, k;
	
	for (int i = 1; i <= n; ++i) {
        int x = (n - 1) / i + 1;
        if (x + i < v) {
            v = x + i;
            m = x;
            k = i;
        }
	}
	
	for (int i = 1; i <= n; i += m) {
        for (int j = min(i + m - 1, n); i <= j; --j) {
            printf("%d ", j);
        }
	}
	
	return 0;
}
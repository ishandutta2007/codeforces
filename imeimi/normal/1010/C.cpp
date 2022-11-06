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

int n, k;

int gcd(int x, int y) {
    if (x < y) swap(x, y);
    if (y == 0) return x;
    return gcd(y, x % y);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	int ret = k;
	for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ret = gcd(x, ret);
	}
	printf("%d\n", k / ret);
	for (int i = 0; i < k; i += ret) {
        printf("%d ", i);
	}
	
	return 0;
}
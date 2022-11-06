#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <functional>
#include <string.h>
#include <math.h>
#include <time.h>

using namespace std;
typedef unsigned long long llong;
typedef long double ld;
typedef pair<int, int> pi;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	llong a, b;
	cin >> a >> b;
	if (b - a > 100) {
		printf("0\n");
		return 0;
	}
	int ans = 1;
	for (llong i = a + 1; i <= b; ++i) {
		ans *= (i % 10);
		ans %= 10;
	}
	printf("%d\n", ans);
	return 0;
}
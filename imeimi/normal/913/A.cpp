#include <iostream>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <memory>
#include <algorithm>
#include <functional>
#include <memory.h>
#include <string.h>
#include <math.h>
#include <time.h>

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<llong, llong> pll;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n, m;
	cin >> n >> m;
	if (n > 30) printf("%d\n", m);
	else printf("%d\n", m & ((1 << n) - 1));

	return 0;
}
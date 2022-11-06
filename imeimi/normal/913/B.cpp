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

int par[1001];
int child[1001];
int leaf[1001];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;
	for (int i = 2; i <= n; ++i) {
		cin >> par[i];
		++child[par[i]];
	}

	for (int i = 1; i <= n; ++i) {
		if (child[i]) continue;
		++leaf[par[i]];
	}

	for (int i = 1; i <= n; ++i) {
		if (child[i] != 0 && leaf[i] < 3) {
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");

	return 0;
}
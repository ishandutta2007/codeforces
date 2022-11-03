


#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <stack>
#include <bitset>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <random>

using namespace std;

//#define FAST_ALLOCATOR_MEMORY 1e8
#undef LOCAL
//#include "optimization.h"

int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	long long k, d, t;
	cin >> k >> d >> t;
	long long ost = ((((k - 1) / d) + 1) * d) - k;
	long long dr = k;


	long long am = (2 * t) / (2 * dr + ost);
	long long ans = 2 * am * (dr + ost);

	long long oth = 2 * t - am * (2 * dr + ost);


	if (2 * dr >= oth) {
		ans += oth;
	}
	else {
		ans += 2 * (oth - dr);
	}



	cout << fixed << setprecision(10) << double(ans) / 2;

	return 0;
}
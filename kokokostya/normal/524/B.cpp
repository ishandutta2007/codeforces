



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

using namespace std;

//#define FAST_ALLOCATOR_MEMORY 1e8
#undef LOCAL
//#include "optimization.h"

const long long MX = 1001;
const long long INF = 1e7;

int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	long long n;
	cin >> n;
	vector< pair<long long, long long> > a(n);
	for (long long i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	long long ans = 1e9;
	for (long long h = 1; h < MX; h++) {
		long long res = 0;
		for (long long i = 0; i < n; i++) {
			long long b = a[i].first;
			long long c = a[i].second;
			if (b > h && c > h)
				res += INF;
			if (max(b, c) <= h)
				res += min(b, c);
			else
				res += max(b, c);
		}
		if (res * 1ll * h < ans)
			ans = res * h;
	}
	cout << ans;
	return 0;
}






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
	int n;
	cin >> n;
	vector<int> v(n), t(n);
	vector< vector<int> > will(n + 1);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> t[i];
	}
	vector<long long> prf(n + 1);
	for (int i = 0; i < n; i++)
		prf[i + 1] = prf[i] + t[i];


	for (int i = 0; i < n; i++) {
		int l = i - 1, r = n;
		while (r - l > 1) {
			int m = (l + r) / 2;
			if (prf[i] + v[i] >= prf[m + 1])
				l = m;
			else
				r = m;
		}
		will[l + 1].push_back(i);
	}

	long long sum = 0;
	for (int i = 0; i < n; i++) {
		sum++;
		long long res = 0;
		for (int j : will[i]) {
			res += (v[j] + prf[j]) - prf[i];
			sum--;
		}
		res += sum * 1ll * t[i];
		cout << res << ' ';
	}

	return 0;
}
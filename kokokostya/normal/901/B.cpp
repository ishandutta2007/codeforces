



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

struct numb {
	numb() : a({ 0 }) {}
	numb(vector<int> a) : a(a) {}

	vector<int> a;
};

numb sum(numb a, numb b) {
	numb c = a;
	for (int i = 0; i < min(a.a.size(), b.a.size()); i++)
		c.a[i] += b.a[i];
	return c;
}

numb up(numb a, int b) {
	numb c = a;
	for (int i = 0; i < a.a.size(); i++)
		c.a[i] *= b;
	return c;
}

bool check(numb a) {
	for (int i = 0; i < a.a.size(); i++) {
		if (abs(a.a[i]) > 1)
			return 0;
	}
	return 1;
}

void print(numb a) {
	cout << a.a.size() - 1 << '\n';
	for (int i : a.a)
		cout << i << ' ';
	cout << '\n';
}

int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<numb> dp(n + 10);
	dp[0] = numb({ 1 });
	dp[1] = numb({ 0, 1 });
	for (int i = 2; i <= n; i++) {

		bool is = 0;
		for (int z = -1; z <= 1; z++) {
			if (z != 0) {
				dp[i] = up(dp[i - 1], z);

				reverse(dp[i].a.begin(), dp[i].a.end());
				dp[i].a.push_back(0);
				reverse(dp[i].a.begin(), dp[i].a.end());

				numb ws = dp[i];
				for (int j = -1; j <= 1; j++) {
					if (j != 0) {
						dp[i] = ws;
						dp[i] = sum(dp[i], up(dp[i - 2], j));
						for (int magic = 0; magic <= 0; magic++) {
							if (check(sum(dp[i], up(dp[i - 1], magic)))) {
								dp[i] = sum(dp[i], up(dp[i - 1], magic));
								is = 1;
								break;
							}
						}
						if (is)
							break;
					}
				}
			}
			if (is)
				break;
		}
		//print(dp[i]);
		if (dp[i].a.back() == -1)
			dp[i] = up(dp[i], -1);
		if (!is) {
			cout << i << ' ';
			return 0;
		}

	}
	print(dp[n]);
	print(dp[n - 1]);
	return 0;
}
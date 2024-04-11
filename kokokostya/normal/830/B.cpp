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

using namespace std;

const int MX = 100001;

int main() {
	ios_base::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	long long ans = 0;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	vector< vector<int> > it(MX);
	for (int i = 0; i < n; i++) {
		it[a[i]].push_back(i);
	}
	int res = 0;
	int last = n;
	int ws = 0;
	for (int i = 0; i < MX; i++) {
		if (!it[i].empty() && it[i][0] < last) {
			ws = i;
			res++;
		}
		else {
			if (!it[i].empty())
				last = it[i].back();
		}
		int up = 0;
		for (int j : it[i]) {
			if (j <= last) {
				ans += res;
				up = j;
			}
			else {
				ans += res - 1;
			}
		}
		if (!it[i].empty())
			last = up;
	}
	cout << ans;
	return 0;
}
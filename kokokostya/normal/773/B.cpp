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

using namespace std;

const int m = 5;
const int INF = 1000 * 1000 * 1000 + 7;

int get(int a, int b) {
	for (int i = 1; i < 6; i++) {
		if (a * (1 << i) > b) {
			return 500 * i;
		}
	}
	return 3000;
}

int main() {
	ios_base::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<int> a(5), b(5);
	for (int i = 0; i < m; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++)
		cin >> b[i];
	vector<int> cnt(m);
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m; j++) {
			int a;
			cin >> a;
			if (a != -1)
				cnt[j]++;
		}
	}
	for (int i = 0; i < m; i++) {
		if (a[i] != -1)
			cnt[i]++;
		else
			a[i] = 250;
		if (b[i] != -1)
			cnt[i]++;
		else
			b[i] = 250;
	}
	int ans = 0;
	bool is = 1;
	while (is) {
		vector<int> mx(m);
		for (int i = 0; i < m; i++) {
			mx[i] = get(cnt[i], n + ans);
		}
		int res1 = 0, res2 = 0;
		for (int i = 0; i < m; i++) {
			res1 += mx[i] - (mx[i] / 250) * a[i];
			res2 += mx[i] - (mx[i] / 250) * b[i];
		}
		if (res1 > res2)
			break;
		bool fin = 1;
		for (int i = 0; i < m; i++) {
			if (a[i] > b[i] && a[i] != 250) {
				cnt[i]++;
				if (mx[i] != 500)
					fin = 0;
			}
			else
				if (mx[i] != 3000)
					fin = 0;
		}
		if (fin)
			is = 0;
		ans++;

	}
	if (!is)
		cout << -1;
	else
		cout << ans;
	return 0;
}
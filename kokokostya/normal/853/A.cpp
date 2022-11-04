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

#define LOCAL

int main() {
	ios_base::sync_with_stdio(false);
#ifndef LOCAL
	freopen("testbrain.in", "r", stdin);
	freopen("testbrain.out", "w", stdout);
#endif
	int n, k;
	cin >> n >> k;
	vector<int> c(n);
	for (int i = 0; i < n; i++)
		cin >> c[i];
	vector<bool> used(k + n);
	vector< pair<int, int> > b(n);
	for (int i = 0; i < n; i++)
		b[i] = { c[i], i };
	sort(b.begin(), b.end());
	for (int i = n; i < k + n; i++)
		used[i] = 1;
	int now = n + k - 1;
	int pos = 0;
	vector<int> ans(n);
	vector<int> back(n);
	for (int i = 0; i < n; i++)
		back[b[i].second] = i;
	for (int i = 0; i < n; i++) {
		if (used[now]) {
			while (pos < n && used[b[pos].second])
				pos++;
			ans[b[pos].second] = now;
			used[b[pos].second] = 1;
			pos++;
		}
		else {
			ans[now] = now;
			used[now] = 1;
		}
		now--;
	}
	long long res = 0;
	for (int i = 0; i < n; i++) {
		res += c[i] * 1ll * (ans[i] - i);
	}
	cout << res << '\n';
	for (int i : ans)
		cout << i + 1 << ' ';
	return 0;
}
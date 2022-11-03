#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int n, s;
	cin >> n >> s;
	vector<int> a(n - 1);
	int ans = 0;
	bool is = 1;
	s--;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int b;
		cin >> b;
		if (i == s && is) {
			is = 0;
			if (b != 0)
				ans++;
		}
		else {
			if (i < s)
				a[i] = b;
			else
				a[i - 1] = b;
			if (b == 0)
				cnt++;
		}
	}
	if (n == 1) {
		cout << ans;
		return 0;
	}
	sort(a.begin(), a.end());
	n--;
	vector<int> have(n);
	ans += cnt;
	have[0] = max(0, a[0] - 1);
	for (int i = 1; i < n; i++) {
		if (a[i] == a[i - 1])
			have[i] = have[i - 1];
		else
			have[i] = have[i - 1] + a[i] - a[i - 1] - 1;
	}
	for (int j = n - 1; j >= 0; j--) {
		if (a[j] && n - 1 - j + cnt >= have[j]) {
			cout << n - 1 - j + ans;
			return 0;
		}
	}
	cout << ans - cnt + n;
	return 0;
}
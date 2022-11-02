#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int a[1000009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	string s; cin >> s;
	int ts = 0, mn = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '(') a[i] = 1;
		else a[i] = -1;
		ts += a[i];
		if (i > 0) a[i] += a[i - 1];
		mn = min(mn, ts);
	}
	if (ts != -2 && ts != 2) {
		cout << 0 << '\n';
		return 0;
	}
	if (ts == 2) {
		if (mn < 0) {
			cout << 0 << '\n';
			return 0;
		}
		int ts = 0, ans = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (a[i] < 2) break;
			if (s[i] == '(') ans++;
		}
		cout << ans << '\n';
	}
	else {
		if (mn < -2) {
			cout << 0 << '\n';
			return 0;
		}
		int ts = 0, ans = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == ')') ans++;
			if (a[i] < 0) break;
		}
		cout << ans << '\n';
	}
	return 0;
}
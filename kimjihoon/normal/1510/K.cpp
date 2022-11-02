#include <iostream>
#include <algorithm>
using namespace std;

int n, ta[2009], a[2009];

void sp(int f)
{
	if (f) {
		for (int i = 1; i <= n; i++)
			swap(a[i], a[n + i]);
	}
	else {
		for (int i = 1; i <= 2 * n; i += 2)
			swap(a[i], a[i + 1]);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= 2 * n; i++) {
		cin >> a[i];
		ta[i] = a[i];
	}
	int ans = 1000000000, s = 0;
	for (int i = 0; i < 2 * n + 2; i++) {
		bool f = true;
		for (int j = 1; j < 2 * n; j++) {
			if (a[j] > a[j + 1]) {
				f = false;
				break;
			}
		}
		if (f) {
			ans = s;
			break;
		}
		s++;
		sp(i & 1);
	}
	s = 0;
	for (int i = 1; i <= 2 * n; i++)
		a[i] = ta[i];
	for (int i = 0; i < 2 * n + 2; i++) {
		bool f = true;
		for (int j = 1; j < 2 * n; j++) {
			if (a[j] > a[j + 1]) {
				f = false;
				break;
			}
		}
		if (f) {
			ans = min(ans, s);
			break;
		}
		s++;
		sp((i + 1) & 1);
	}
	if (ans == 1000000000) cout << -1 << '\n';
	else cout << ans << '\n';
	return 0;
}